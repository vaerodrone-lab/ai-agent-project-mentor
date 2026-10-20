# KHO DỮ KIỆN KINH NGHIỆM & BÀI HỌC THỰC NGHIỆM IOT (EXPERIENCE KNOWLEDGE BASE)
> *Nơi tích lũy toàn bộ các sự cố kỹ thuật thực tế, phân tích nguyên nhân gốc rễ và giải pháp chuẩn hóa nhằm phục vụ tra cứu và tái sử dụng cho các dự án kỹ thuật liên quan.*

---

## 1. THẺ KINH NGHIỆM 01: SỰ CỐ SỤT ÁP NGUỒN (BROWNOUT RESET) DO ĐỘNG CƠ SERVO
* **Hiện tượng:** Khi nạp chương trình vào ESP32, màn hình LCD hiển thị bình thường, nhưng khi thanh chắn barie bắt đầu chuyển động quay thì ESP32 sập nguồn và khởi động lại liên tục (vòng lặp reset ngắt quãng).
* **Bản chất kỹ thuật:** Động cơ Servo MG90S khi khởi động hoặc gặp tải cơ học cần dòng điện tức thời lên đến 800mA – 1A (Stall Current). Mạch ổn áp tích hợp trên bo ESP32 chỉ cung cấp tối đa khoảng 500mA cho toàn mạch. Khi dòng tiêu thụ tăng đột biến, điện áp trên đường 5V/3.3V tụt xuống dưới ngưỡng an toàn (2.8V), kích hoạt cơ chế bảo vệ Brownout Detector tích hợp trong chip ESP32 tự ngắt để bảo vệ dữ liệu flash.
* **Giải pháp kỹ thuật chuẩn hóa:**
  1. Tách riêng đường nguồn nuôi động cơ: Không cấp nguồn dương (+5V) của Servo từ chân 3.3V hoặc 5V của cổng USB trên bo ESP32.
  2. Sử dụng nguồn ngoài 5V độc lập từ adapter DC hoặc mạch hạ áp Buck (LM2596 / AMS1117).
  3. Bắt buộc nối chung chân mass (Common Ground) giữa nguồn nuôi Servo và bo ESP32.
  4. Mắc song song một tụ điện hóa 470µF – 1000µF giữa chân VCC và GND của Servo để đệm dòng tức thời khi khởi động.
* **Khuyến nghị kiến trúc:** Mọi tải cảm ứng và cơ cấu chấp hành công suất (động cơ, rơ-le, van điện từ) đều phải sử dụng nguồn động lực riêng biệt với nguồn điều khiển của vi điều khiển.

---

## 2. THẺ KINH NGHIỆM 02: CẢM BIẾN FC-51 BÁO SAI TRẠNG THÁI DO PHẢN XẠ SÀN FOMEX
* **Hiện tượng:** Trên giao diện Web và màn hình LCD luôn hiển thị trạng thái "CẢ 4 Ô ĐÃ CÓ XE" mặc dù thực tế trên sa bàn hoàn toàn không có phương tiện.
* **Bản chất kỹ thuật:** 
  1. Vật liệu sa bàn là tấm Fomex trắng có hệ số phản xạ tia hồng ngoại cao (~90%).
  2. Biến trở so sánh trên mô-đun FC-51 được tinh chỉnh ở ngưỡng độ nhạy quá cao, khiến chùm tia hồng ngoại phát ra dội ngược từ mặt sàn trắng vào đầu thu photodiode đủ vượt ngưỡng kích hoạt của IC so sánh LM393, kéo ngõ ra về mức 0V (LOW = Có xe).
* **Giải pháp kỹ thuật chuẩn hóa:**
  1. Sử dụng tuốc-nơ-vít xoay biến trở trên lưng từng mô-đun FC-51 **ngược chiều kim đồng hồ** từ từ cho đến khi đèn LED chỉ thị tín hiệu ngắt hoàn toàn khi ô đỗ trống.
  2. Đặt mô hình phương tiện vào cự ly 4 – 5 cm, quan sát đèn LED chỉ thị bật sáng ổn định; khi rút phương tiện ra đèn phải tắt ngay lập tức.
* **Khuyến nghị kiến trúc:** Cảm biến quang hồng ngoại phụ thuộc lớn vào bề mặt và màu sắc vật cản. Cần thực hiện quy trình hiệu chuẩn ngưỡng trên môi trường vật lý thực tế trước khi vận hành hệ thống.

---

## 3. THẺ KINH NGHIỆM 03: NGHỊCH ĐẢO MỨC LOGIC TRONG CHƯƠNG TRÌNH (#define DETECT)
* **Hiện tượng:** Khi đặt vật cản vào cảm biến thì hệ thống báo "CÒN TRỐNG", khi rút vật cản ra thì báo "ĐÃ CÓ XE".
* **Bản chất kỹ thuật:** Tùy thuộc vào thiết kế mạch so sánh của nhà sản xuất, một số dòng mô-đun quang xuất mức HIGH khi phát hiện vật cản và LOW khi không có vật cản, ngược với giả định mức logic ban đầu trong mã nguồn (`#define DETECT LOW`).
* **Giải pháp kỹ thuật chuẩn hóa:** Xác định mức logic thực tế qua thực nghiệm: nếu trạng thái tín hiệu bị nghịch đảo toàn phần, điều chỉnh định nghĩa tiền xử lý trong mã nguồn:
  ```cpp
  #define DETECT HIGH  // Thay đổi từ LOW sang HIGH tùy theo đặc tính module
  ```
* **Khuyến nghị kiến trúc:** Trước khi tích hợp cảm biến vào hệ thống lớn, luôn nạp đoạn mã đọc tín hiệu số (`digitalRead`) đơn giản hiển thị ra Serial Monitor để xác định chuẩn mức logic tích cực.

---

## 4. THẺ KINH NGHIỆM 04: MÀN HÌNH LCD 1602 HIỂN THỊ KHỐI VUÔNG ĐEN
* **Hiện tượng:** Màn hình LCD sáng đèn nền nhưng chỉ xuất hiện 16 khối vuông đen ở dòng thứ nhất, không hiển thị ký tự dữ liệu.
* **Bản chất kỹ thuật:** 
  1. Nguyên nhân 1: Biến trở vi chỉnh độ tương phản (Contrast) màu xanh phía sau bo I2C chưa được thiết lập đúng mức điện áp phân cực.
  2. Nguyên nhân 2: Bo chuyển đổi I2C sử dụng chip PCF8574A có địa chỉ mặc định là `0x3F`, trong khi chương trình đang cấu hình địa chỉ mặc định là `0x27`.
* **Giải pháp kỹ thuật chuẩn hóa:**
  1. Điều chỉnh nhẹ biến trở tương phản sau lưng màn hình cho đến khi các ký tự hiển thị rõ nét.
  2. Nạp đoạn mã `I2C Scanner` vào ESP32 để dò tìm địa chỉ hex thực tế trên đường truyền I2C và cập nhật vào dòng lệnh khởi tạo `LiquidCrystal_I2C lcd(address, 16, 2)`.

---

## 5. THẺ KINH NGHIỆM 05: KHÔNG KẾT NỐI ĐƯỢC WEB SERVER CỦA ESP32 QUA TRÌNH DUYỆT
* **Hiện tượng:** Bo ESP32 đã kết nối vào mạng Wi-Fi và nhận địa chỉ IP hợp lệ, nhưng thiết bị di động truy cập địa chỉ IP này thì trình duyệt báo lỗi từ chối kết nối (ERR_CONNECTION_REFUSED hoặc Timeout).
* **Bản chất kỹ thuật:** 
  1. Thiết bị di động đang ưu tiên sử dụng mạng dữ liệu di động (4G/LTE) hoặc kết nối vào một Access Point/băng tần khác (ví dụ: Wi-Fi 5GHz trong khi ESP32 kết nối Wi-Fi 2.4GHz).
  2. Điểm truy cập Wi-Fi (Router) đang kích hoạt tính năng cách ly client nội bộ (AP Isolation / Client Isolation), ngăn các thiết bị trong cùng mạng LAN giao tiếp trực tiếp với nhau.
* **Giải pháp kỹ thuật chuẩn hóa:**
  1. Tắt mạng dữ liệu di động 4G trên điện thoại, đảm bảo kết nối cùng mạng Wi-Fi băng tần 2.4GHz với ESP32.
  2. Nhập chính xác giao thức và địa chỉ IP trực tiếp trên thanh địa chỉ của trình duyệt (ví dụ: `http://192.168.1.15`).
  3. Trong trường hợp hạ tầng mạng hạn chế, cấu hình ESP32 hoạt động ở chế độ Điểm truy cập độc lập (`WiFi.softAP()`) để các thiết bị kết nối trực tiếp vào mạng do ESP32 phát ra.
