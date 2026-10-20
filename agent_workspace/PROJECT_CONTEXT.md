# BỐI CẢNH HIỆN TRẠNG DỰ ÁN SMART PARKING (PROJECT CONTEXT)
> *Tài liệu cập nhật trạng thái mới nhất của dự án để các Agent tiếp nối làm việc.*

---

## 1. THÔNG SỐ PHẦN CỨNG THỰC TẾ
* **Khung sa bàn:** Fomex màu trắng, 4 vị trí đỗ xe bố trí chéo, 1 làn đường duy nhất cho cổng vào/ra.
* **Vi điều khiển:** ESP32-WROOM-32 (DevKit 30 chân) cắm trên bo test (perfboard).
* **Cảm biến đỗ xe:** 4 cảm biến quang hồng ngoại FC-51 gắn đối diện ô đỗ 1, 2, 3, 4 (chân GPIO 32, 33, 25, 26).
* **Cảm biến cổng:** 2 cảm biến quang FC-51 (S1 ngoài - GPIO 27, S2 trong - GPIO 14).
* **Cơ cấu chấp hành:** Động cơ Micro Servo TowerPro MG90S bánh răng kim loại gắn thanh barie xốp trắng (chân tín hiệu PWM - GPIO 18).
* **Màn hình hiển thị:** LCD 1602 (xanh lá) có mạch I2C PCF8574 (chân SDA - GPIO 21, SCL - GPIO 22, địa chỉ hex `0x27`).
* **Nguồn điện:** Jack DC ngoài cấp nguồn cho mạch hạ áp 5V.

---

## 2. HIỆN TRẠNG PHẦN MỀM (`firmware/it.ino`)
* Chương trình chạy Web Server nội bộ ở cổng 80 (chế độ Wi-Fi Station `WiFi.mode(WIFI_STA)`).
* Trả về giao diện Web HTML/CSS/JS tại đường dẫn gốc `/`.
* Cung cấp API dữ liệu JSON tại `/data`:
  ```json
  {"used": 2, "free": 2, "gate": "CLOSED", "slots": [true, false, true, false]}
  ```
* Cơ chế cập nhật Web: Client chạy hàm JavaScript `fetch('/data')` định kỳ mỗi 1000ms.
* Màn hình LCD luân phiên hiển thị địa chỉ IP và số chỗ trống.

---

## 3. SỰ CỐ KỸ THUẬT GẦN NHẤT & HƯỚNG XỬ LÝ (BUG TRACKING)

### ⚠️ Lỗi ghi nhận: "Trên Web báo cả 4 ô đỗ đều đang có xe (trong khi thực tế bãi trống)"
* **Bản chất kỹ thuật:** Cả 4 chân GPIO (32, 33, 25, 26) đều đang đọc được mức logic `LOW (0V)`, trong khi code định nghĩa `#define DETECT LOW`.
* **3 nguyên nhân cần mentee và Agent kiểm tra trên mạch thực tế:**
  1. *Ngược logic cảm biến:* Loại module FC-51 này có thể xuất mức HIGH khi thấy vật cản. Thử che tay vào cảm biến ô 1, nếu web đổi sang "CÒN TRỐNG" &rarr; Sửa code thành `#define DETECT HIGH`.
  2. *Bắt nhầm mặt sàn Fomex trắng:* Fomex trắng phản xạ tia hồng ngoại cực mạnh, biến trở chỉnh quá nhạy khiến cảm biến tưởng mặt sàn là xe. Cần lấy vít xoay biến trở trên lưng module ngược chiều kim đồng hồ cho đèn tín hiệu tắt.
  3. *Mất nguồn dương VCC cụm cảm biến:* Cả 4 cảm biến nối chung nguồn, nếu dây VCC 5V bị tuột &rarr; IC LM393 mất điện &rarr; OUT tụt về 0V &rarr; ESP32 đọc LOW cả 4 con.

---

## 4. HƯỚNG PHÁT TRIỂN TIẾP THEO (ROADMAP CUỐI KỲ)
* [ ] Kiểm tra và tinh chỉnh dứt điểm độ nhạy của 4 cảm biến ô đỗ trên sa bàn.
* [ ] Thêm thuật toán lọc nhiễu phần mềm (Software Debounce) để tránh hiện tượng barie đóng mở chập chờn do ánh sáng đèn phòng.
* [ ] Mở rộng kết nối Cloud qua giao thức **MQTT** (Adafruit IO hoặc HiveMQ) để theo dõi bãi xe từ xa qua 4G/Internet (đáp ứng chuẩn CLO 304-K06, K10).
* [ ] Nghiên cứu tích hợp camera ESP32-CAM nhận diện biển số xe (CLO 304-S10 - AI trong IoT).
