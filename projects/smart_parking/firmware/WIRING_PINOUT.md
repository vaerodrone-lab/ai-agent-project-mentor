# BẢNG TRA CỨU ĐẤU NỐI CHÂN & QUY TẮC NGUỒN ĐIỆN (PINOUT & WIRING)

---

## 1. BẢNG MAPPING CHÂN VI ĐIỀU KHIỂN ESP32 DEVKIT

| Tên chân ESP32 | Chế độ GPIO | Thiết bị kết nối | Vị trí trên sa bàn | Quy ước mức Logic |
| :---: | :---: | :--- | :--- | :--- |
| **GPIO 27** | `INPUT_PULLUP` | Cảm biến ngoài cổng (S1) | Trước thanh barie | `LOW = Thấy xe` \| `HIGH = Trống` |
| **GPIO 14** | `INPUT_PULLUP` | Cảm biến trong cổng (S2) | Sau thanh barie | `LOW = Thấy xe` \| `HIGH = Trống` |
| **GPIO 32** | `INPUT_PULLUP` | Cảm biến Ô đỗ số 1 | Ô đỗ số 1 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 33** | `INPUT_PULLUP` | Cảm biến Ô đỗ số 2 | Ô đỗ số 2 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 25** | `INPUT_PULLUP` | Cảm biến Ô đỗ số 3 | Ô đỗ số 3 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 26** | `INPUT_PULLUP` | Cảm biến Ô đỗ số 4 | Ô đỗ số 4 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 18** | `TIMER PWM OUT` | Dây tín hiệu cam của Servo MG90S | Cổng barie | Xung 50Hz (0.5ms = 0° \| 1.5ms = 90°) |
| **GPIO 21** | `I2C SDA` | Chân SDA module LCD 1602 I2C | Dưới cổng chắn | Đường truyền dữ liệu chuỗi bit |
| **GPIO 22** | `I2C SCL` | Chân SCL module LCD 1602 I2C | Dưới cổng chắn | Đường xung nhịp đồng bộ |
| **VIN / GND** | `POWER` | Nguồn cấp hệ thống | Góc dưới trái | Nguồn 5V DC và Mass chung (Common Ground) |

---

## 2. NGUYÊN TẮC AN TOÀN NGUỒN CÔNG SUẤT (TRÁNH SỤT ÁP BROWNOUT)
1. **Không nuôi Servo bằng chân 3.3V của ESP32:** Động cơ Servo MG90S khi đề-pa rút dòng lên đến 800mA, sẽ làm sụt áp khiến ESP32 bị reset liên tục.
2. **Cấp nguồn 5V riêng cho Servo:** Lấy nguồn dương 5V từ mạch nguồn DC ngoài hoặc mạch hạ áp riêng.
3. **Nối chung Mass (Common Ground):** Chân GND của nguồn ngoài, GND của Servo và chân GND của ESP32 bắt buộc phải nối thông với nhau.
