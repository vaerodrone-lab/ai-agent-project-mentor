# KHO DỮ KIỆN KINH NGHIỆM & BÀI HỌC THỰC CHIẾN IOT (EXPERIENCE KNOWLEDGE BASE)
> *Nơi tích lũy toàn bộ các "bệnh thực địa", bài học xương máu và giải pháp dứt điểm để các Agent và Mentee tái sử dụng cho các dự án sau này.*

---

##  কার্ড CARD 01: LỖI SỤT ÁP NGUỒN (BROWNOUT RESET) DO ĐỘNG CƠ SERVO
* **Hiện tượng:** Khi nạp code vào ESP32, màn hình LCD sáng, nhưng cứ hễ đến lúc barie bắt đầu quay là ESP32 bị sập nguồn, khởi động lại liên tục (vòng lặp reset vô tận).
* **Bản chất kỹ thuật:** Động cơ Servo MG90S khi bắt đầu khởi động hoặc gặp lực cản cơ học cần dòng điện tức thời lên đến 800mA – 1A (Stall Current). Mạch ổn áp trên chip ESP32 chỉ cấp tối đa khoảng 500mA cho toàn bo. Khi Servo "uống" dòng quá nhanh, điện áp đường 5V/3.3V bị tụt xuống dưới 2.8V, kích hoạt mạch bảo vệ Brownout Detector trong chip ESP32 tự ngắt để bảo vệ bộ nhớ.
* **Giải pháp chuẩn:**
  1. Tuyệt đối không cắm chân nguồn dương (+5V) của Servo vào chân 3.3V hoặc chân 5V của cổng nạp USB trên ESP32.
  2. Cấp nguồn 5V riêng cho Servo từ cổng DC Jack ngoài hoặc module hạ áp buck LM2596/AMS1117.
  3. Bắt buộc nối chung dây mass (Common Ground) giữa nguồn ngoài và ESP32.
  4. Hàn thêm một tụ điện hóa 470uF song song giữa chân VCC và GND của Servo để trữ điện đệm dòng lúc đề-pa.
* **Bài học cho project sau:** Mọi tải cảm kháng (động cơ, rơ-le, còi buzzer công suất lớn) đều phải tách nguồn công suất độc lập với vi điều khiển.

---

## কার্ড CARD 02: LỖI CẢM BIẾN FC-51 BÁO ẢO DO PHẢN XẠ SÀN FOMEX TRẮNG
* **Hiện tượng:** Trên Web và màn hình LCD luôn báo "CẢ 4 Ô ĐÃ CÓ XE" mặc dù trên sa bàn hoàn toàn trống không có xe nào.
* **Bản chất kỹ thuật:** 
  1. Vật liệu sa bàn làm bằng Fomex màu trắng có độ phản xạ tia hồng ngoại cực kỳ cao (~90%).
  2. Biến trở vi chỉnh trên lưng module FC-51 đang vặn ngưỡng so sánh quá nhạy, khiến chùm tia hồng ngoại chiếu xuống mặt sàn trắng dội ngược lại photodiode thu cũng đủ làm IC LM393 lật mức 0V (LOW = Có xe).
* **Giải pháp chuẩn:**
  1. Lấy tuốc-nơ-vít nhỏ vặn biến trở trên từng cảm biến **ngược chiều kim đồng hồ** từ từ cho đến khi đèn LED báo tín hiệu vừa tắt hẳn khi ô trống.
  2. Đưa mô hình xe vào cự ly 4 – 5 cm, đèn phải sáng lên dứt khoát; rút xe ra đèn phải tắt ngay.
* **Bài học cho project sau:** Cảm biến quang rất nhạy cảm với màu sắc và bề mặt vật liệu. Luôn phải cân chỉnh ngưỡng so sánh trên môi trường thực tế trước khi chạy chương trình.

---

## কার্ড CARD 03: LỖI NGƯỢC MỨC LOGIC TRONG CHƯƠNG TRÌNH (#define DETECT)
* **Hiện tượng:** Khi che tay vào cảm biến thì Web báo "CÒN TRỐNG", khi bỏ tay ra thì Web báo "ĐÃ CÓ XE".
* **Bản chất kỹ thuật:** Một số lô module cảm biến quang học xuất mức HIGH khi thấy vật cản và LOW khi trống, trong khi code đang mặc định `#define DETECT LOW`.
* **Giải pháp chuẩn:** Kiểm tra bằng thực nghiệm: nếu trạng thái bị nghịch đảo 100%, chỉ cần đổi trong file code:
  ```cpp
  #define DETECT HIGH  // Thay vì #define DETECT LOW
  ```
* **Bài học cho project sau:** Luôn viết một đoạn code test đọc `digitalRead()` in ra Serial Monitor trước khi ghép vào hệ thống lớn để xác định chắc chắn mức logic kích hoạt của cảm biến.

---

## কার্ড CARD 04: LỖI MÀN HÌNH LCD 1602 HIỆN KHỐI VUÔNG ĐEN
* **Hiện tượng:** Màn hình LCD sáng đèn nền nhưng chỉ hiện 16 khối vuông đen ở dòng 1, không hiển thị bất kỳ chữ số nào.
* **Bản chất kỹ thuật:** 
  1. Nguyên nhân 1: Biến trở chỉnh độ tương phản (Contrast) màu xanh dương sau lưng bo I2C chưa được tinh chỉnh đúng mức điện áp.
  2. Nguyên nhân 2: Module I2C dùng chip PCF8574A có địa chỉ mặc định là `0x3F` nhưng trong code lại khai báo `LiquidCrystal_I2C lcd(0x27, 16, 2)`.
* **Giải pháp chuẩn:**
  1. Xoay biến trở sau lưng màn hình từ từ đến khi chữ hiện rõ.
  2. Nếu không được, nạp chương trình `I2C Scanner` vào ESP32 để quét địa chỉ hex thực tế và cập nhật vào code.

---

## কার্ড CARD 05: LỖI ĐIỆN THOẠI KHÔNG TRUY CẬP ĐƯỢC WEB SERVER CỦA ESP32
* **Hiện tượng:** ESP32 đã kết nối Wi-Fi và có IP, nhưng gõ IP trên điện thoại thì trình duyệt báo lỗi "Không thể kết nối máy chủ" (ERR_CONNECTION_REFUSED).
* **Bản chất kỹ thuật:** 
  1. Điện thoại đang bật 4G/LTE hoặc đang kết nối mạng Wi-Fi khác băng tần/khác tên với ESP32.
  2. Router Wi-Fi bật tính năng cách ly thiết bị nội bộ (AP Isolation / Client Isolation) ngăn các máy con giao tiếp với nhau.
* **Giải pháp chuẩn:**
  1. Tắt mạng di động 4G trên điện thoại, đảm bảo bắt chung một mạng Wi-Fi 2.4GHz với ESP32.
  2. Gõ trực tiếp địa chỉ IP (ví dụ: `http://192.168.1.15`), không gõ vào ô tìm kiếm của Google.
  3. Nếu router chặn, có thể cấu hình ESP32 sang chế độ Access Point (`WiFi.softAP()`) để điện thoại kết nối trực tiếp vào Wi-Fi do ESP32 tự phát ra.
