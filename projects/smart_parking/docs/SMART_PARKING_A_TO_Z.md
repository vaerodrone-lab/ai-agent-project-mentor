# CẨM NANG KỸ THUẬT: PHÂN TÍCH BẢN CHẤT HỆ THỐNG BÃI ĐỖ XE THÔNG MINH
> **Mục tiêu tài liệu:** Bóc tách bản chất phần cứng, dòng chảy tín hiệu và giải thuật vận hành nhúng của hệ thống Bãi đỗ xe thông minh (Smart Parking System).
> 
> **Lộ trình 5 tầng tư duy kỹ thuật:**
> 1. **Tầng 1: Giải Phẫu Mô Hình Thực Tế** (Quan sát trực diện sa bàn, phân định 4 phân khu chức năng).
> 2. **Tầng 2: 5 Bài Toán Thực Tế & Cách Hệ Thống Giải Quyết** (Tư duy nhân quả: Vấn đề kỹ thuật → Giải pháp linh kiện & giải thuật).
> 3. **Tầng 3: Bản Đồ Kết Nối** (Phân định Nguồn động lực & Tín hiệu điều khiển, bảng pinout, các chân đặc biệt).
> 4. **Tầng 4: Cơ Chế Vận Hành Nhúng Của ESP32** (Giải mã logic máy trạng thái FSM và cơ chế định thời không khóa `millis()`).
> 5. **Tầng 5: Phương Pháp Luận Chẩn Đoán Sự Cố & Phản Biện Chuyên Môn** (Chẩn đoán 5 sự cố điển hình & Bộ câu hỏi cốt lõi).

---

# TẦNG 1: GIẢI PHẪU MÔ HÌNH THỰC TẾ TRÊN SA BÀN

Quan sát trực tiếp mô hình sa bàn Fomex của đề tài, toàn bộ hệ thống được phân định thành 4 khu vực chức năng rõ rệt:

```
┌────────────────────────────────────────────────────────────────────────┐
│ [LỐI VÀO / RA]                     [KHU VỰC 4 Ô ĐỖ XE]                 │
│                                                                        │
│  • Mắt ngoài (S1)                   Ô 1: [Mắt IR 1] ───► Chân GPIO 32  │
│         │                                                              │
│  • Cần chắn Barie (Servo MG90S)     Ô 2: [Mắt IR 2] ───► Chân GPIO 33  │
│         │                                                              │
│  • Mắt trong (S2)                   Ô 3: [Mắt IR 3] ───► Chân GPIO 25  │
│                                                                        │
│  • Bảng báo LCD 1602 I2C            Ô 4: [Mắt IR 4] ───► Chân GPIO 26  │
│                                                                        │
│ ────────────────────────────────────────────────────────────────────── │
│ [TRUNG TÂM ĐIỀU KHIỂN & NGUỒN] (Góc dưới bên trái)                     │
│  • Bo vi điều khiển ESP32 DevKit V1 (30 chân)                          │
│  • Jack cắm nguồn DC ngoài & Module hạ áp 5V                           │
└────────────────────────────────────────────────────────────────────────┘
```

### Bảng Giải Phẫu Chi Tiết 4 Khu Vực Chức Năng:
1. **[1] Phân khu Điều khiển Trung tâm & Nguồn (Góc dưới bên trái):** Bo vi điều khiển ESP32 gắn trên perfboard kèm jack DC và mạch nguồn ổn áp. Đóng vai trò là **Bộ xử lý trung tâm**: tiếp nhận tín hiệu từ các cảm biến, thực thi giải thuật FSM, điều khiển cơ cấu chấp hành và khởi tạo Web Server.
2. **[2] Phân khu Giám sát Vị trí Đỗ (Dãy bên phải):** 04 cảm biến quang hồng ngoại FC-51 gắn đối diện các vách ngăn đỗ chéo (đánh số 1, 2, 3, 4). Đóng vai trò là **Trạm giám sát hiện diện**: nhận diện phương tiện chiếm chỗ và gửi tín hiệu logic về bộ xử lý trung tâm.
3. **[3] Phân khu Kiểm soát Cổng (Lối vào / ra bên trái):** Động cơ Servo MG90S gắn thanh barie, kết hợp 2 cảm biến quang học S1 (ngoài) và S2 (trong). Đóng vai trò là **Trạm điều phối lưu thông hai chiều**: xác định hướng di chuyển của phương tiện và đảm bảo an toàn khoảng cách khi đóng/mở cổng.
4. **[4] Phân khu Hiển thị Trực quan Cục bộ (Phía dưới cổng chắn):** Màn hình LCD 1602 kết hợp bo chuyển đổi I2C PCF8574. Đóng vai trò là **Giao diện thông tin tại chỗ**: hiển thị địa chỉ IP mạng nội bộ, tổng số phương tiện và số vị trí còn trống trong bãi.

---

# TẦNG 2: 5 BÀI TOÁN THỰC TẾ & CÁCH HỆ THỐNG GIẢI QUYẾT

Thay vì ghi nhớ máy móc các thông số linh kiện, dưới đây là phân tích bản chất mối liên hệ giữa bài toán kỹ thuật thực tế và giải pháp thiết kế:

### 📌 Bài toán 1: Nhận diện trạng thái chiếm chỗ của từng vị trí đỗ
* **Thách thức:** Cần chuyển đổi trạng thái vật lý (có phương tiện hay không) thành tín hiệu điện tương thích với vi điều khiển.
* **Giải pháp kỹ thuật: Cảm biến quang hồng ngoại FC-51.**
  * *Nguyên lý phát – thu quang học:* Mô-đun tích hợp 1 đèn LED phát chùm tia hồng ngoại bước sóng ~940nm và 1 đầu thu quang học (Photodiode).
  * *Khi vị trí đỗ trống:* Chùm tia hồng ngoại phát tán vào không gian và suy hao → Đầu thu không tiếp nhận tín hiệu phản xạ.
  * *Khi có phương tiện:* Thân xe phản xạ chùm tia hồng ngoại trở lại đầu thu.
  * *Cơ chế so sánh ngưỡng qua IC LM393:* Điện áp sinh ra trên đầu thu được đưa vào IC so sánh LM393 so với điện áp ngưỡng do biến trở thiết lập:
    * Có phương tiện: Ngõ ra OUT kéo xuống mass (**Mức LOW = 0V**).
    * Không có phương tiện: Ngõ ra OUT duy trì điện áp nguồn (**Mức HIGH = 3.3V / 5V**).
* **Bản chất kỹ thuật cốt lõi:** Ngõ ra cảm biến xuất mức **LOW tương ứng CÓ XE**, mức **HIGH tương ứng VỊ TRÍ TRỐNG**. Biến trở trên mô-đun dùng để định lượng khoảng cách ngưỡng phát hiện.

---

### 📌 Bài toán 2: Phân định hướng di chuyển (Vào hay Ra) trên cùng một làn đường đơn
* **Thách thức:** Nếu chỉ bố trí 1 cảm biến tại cổng, hệ thống chỉ ghi nhận có phương tiện mà không phân biệt được hướng di chuyển để tính toán vị trí trống tương ứng.
* **Giải pháp kỹ thuật: Bố trí cặp cảm biến nối tiếp theo thời gian (S1 ngoài và S2 trong).**
  * Thanh chắn barie đặt ở giữa hai cảm biến. Cảm biến S1 bố trí phía ngoài; cảm biến S2 bố trí phía trong bãi đỗ.
  * *Phương tiện VÀO:* Phương tiện di chuyển từ ngoài vào sẽ kích hoạt **S1 trước**. Khi S1 = LOW và S2 = HIGH, hệ thống xác định hướng vào. Nếu bãi còn vị trí trống (`freeSlots > 0`), cổng sẽ mở.
  * *Phương tiện RA:* Phương tiện di chuyển từ trong ra sẽ kích hoạt **S2 trước**. Khi S2 = LOW và S1 = HIGH, hệ thống xác định hướng ra và lập tức mở cổng mà không phụ thuộc vào số lượng chỗ trống.
* **Bản chất kỹ thuật cốt lõi:** Áp dụng nguyên lý *Kích hoạt tuần tự theo thời gian (Sequential Temporal Triggering)* để xác định vector chuyển động của đối tượng.

---

### 📌 Bài toán 3: Điều khiển góc quay chính xác và đảm bảo an toàn hành lang cổng
* **Thách thức:** Động cơ DC thông thường không có khả năng định vị góc quay chính xác. Đồng thời, cần cơ chế ngăn chặn việc thanh chắn hạ xuống khi phương tiện chưa thoát ly hoàn toàn khỏi khu vực cổng.
* **Giải pháp kỹ thuật: Động cơ Servo MG90S kết hợp giải thuật kiểm soát vùng an toàn (Clearance Time).**
  * *Điều khiển vị trí bằng xung độ rộng PWM:* Động cơ Servo tích hợp mạch phản hồi góc và chiết áp nội. Vi điều khiển phát tín hiệu PWM chu kỳ 20ms: độ rộng xung 0.5ms tương ứng góc đóng 0°, độ rộng xung 1.5ms tương ứng góc mở 90°.
  * *Cơ chế an toàn hai lớp:* Khi thanh chắn đang mở, phương tiện di chuyển qua cổng sẽ kích hoạt cảm biến thứ hai (xác nhận phương tiện đã đi vào vùng giao cắt). Quá trình đóng cổng chỉ được thực thi khi thỏa mãn đồng thời:
    1. Cả hai cảm biến S1 và S2 đều không còn phát hiện vật cản.
    2. Trạng thái thông thoáng duy trì liên tục vượt ngưỡng thời gian quy định **(1.2 giây)** nhằm đảm bảo đuôi phương tiện đã vượt qua phạm vi quét của thanh chắn.
    3. Nếu bất kỳ cảm biến nào bị kích hoạt lại trong thời gian này, bộ đếm định thời sẽ tự động đặt lại từ đầu.

---

### 📌 Bài toán 4: Tối ưu hóa số lượng chân giao tiếp của màn hình LCD 1602
* **Thách thức:** Giao diện điều khiển trực tiếp của LCD 1602 đòi hỏi tối thiểu 6 đến 16 chân GPIO, dẫn đến thiếu hụt tài nguyên chân trên vi điều khiển.
* **Giải pháp kỹ thuật: Ứng dụng giao thức bus I2C thông qua IC mở rộng PCF8574.**
  * Màn hình được kết nối thông qua mô-đun I2C mang IC PCF8574 (địa chỉ mặc định `0x27`).
  * Hệ thống chỉ cần sử dụng 2 đường tín hiệu: **SDA (GPIO 21)** để truyền dữ liệu nối tiếp và **SCL (GPIO 22)** để đồng bộ xung nhịp nhị phân.
  * IC PCF8574 giải mã dòng bit nối tiếp thành dữ liệu song song 8-bit điều khiển trực tiếp các chân của LCD.

---

### 📌 Bài toán 5: Giám sát trạng thái bãi đỗ không dây thời gian thực
* **Thách thức:** Giám sát bãi xe từ xa bằng thiết bị di động mà không cần trang bị thêm phần cứng mạng rời hoặc cáp truyền dẫn.
* **Giải pháp kỹ thuật: Khai thác khối vô tuyến Wi-Fi và kiến trúc Web Server nhúng của ESP32.**
  * ESP32 tích hợp phần cứng thu phát Wi-Fi 2.4GHz. Firmware khởi tạo một máy chủ Web (HTTP Server) lắng nghe tại cổng 80:
    * Khi thiết bị di động gửi yêu cầu GET tới đường dẫn gốc `/`, ESP32 phản hồi trang giao diện HTML/CSS/JavaScript.
    * Định kỳ mỗi 1000ms, mã lệnh JavaScript phía client thực thi hàm `fetch('/data')` để truy vấn trạng thái từ ESP32. ESP32 phản hồi chuỗi dữ liệu định dạng JSON: `{"used": 2, "free": 2, "slots": [...]}`, cho phép giao diện tự động cập nhật trực quan mà không cần tải lại toàn bộ trang web.

---

# TẦNG 3: BẢN ĐỒ KẾT NỐI (DÒNG NĂNG LƯỢNG & DÒNG TÍN HIỆU)

Toàn bộ hệ thống kết nối được phân định rõ ràng thành hai hệ thống độc lập:

### 1. Hệ Nguồn Động Lực & Hiện Tượng Sụt Áp (Brownout Reset)
* Đường nguồn nuôi chính (+5V) và đường mass chung (GND).
* **Nguyên lý sụt áp:** Động cơ Servo MG90S khi khởi động hoặc chuyển hướng có thể tiêu thụ dòng tức thời lên tới 1A (Stall Current). Nếu nối chung nguồn Servo với chân 3.3V hoặc ngõ ra 5V hạn dòng của chip nạp USB, sự sụt áp đột ngột sẽ kích hoạt mạch Brownout Detector tích hợp trong ESP32, gây hiện tượng khởi động lại liên tục.
* **Quy chuẩn đấu nối:** Sử dụng nguồn ngoài 5V – 2A riêng biệt cho động cơ Servo, đồng thời **bắt buộc nối chung chân GND** giữa nguồn ngoài và bo ESP32 để đồng nhất mốc điện thế tham chiếu.

### 2. Hệ Tín Hiệu Điều Khiển & Bảng Ánh Xạ Chân (Pinout Map)

| Chân ESP32 | Tên mô-đun | Chức năng kỹ thuật | Mức logic chuẩn |
| :---: | :--- | :--- | :--- |
| **GPIO 27** | Cảm biến cổng ngoài (S1) | Giám sát phương tiện tiếp cận cổng vào | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 14** | Cảm biến cổng trong (S2) | Giám sát phương tiện tiếp cận cổng ra / kiểm soát hành lang | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 32** | Cảm biến Ô đỗ 1 | Giám sát trạng thái chiếm chỗ vị trí 1 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 33** | Cảm biến Ô đỗ 2 | Giám sát trạng thái chiếm chỗ vị trí 2 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 25** | Cảm biến Ô đỗ 3 | Giám sát trạng thái chiếm chỗ vị trí 3 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 26** | Cảm biến Ô đỗ 4 | Giám sát trạng thái chiếm chỗ vị trí 4 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 18** | Tín hiệu Servo MG90S | Xung điều khiển góc quay PWM | `0.5ms = 0°` \| `1.5ms = 90°` |
| **GPIO 21** | Đường SDA của LCD | Truyền nhận dữ liệu nối tiếp I2C | Giao thức truyền thông I2C Bus |
| **GPIO 22** | Đường SCL của LCD | Đồng bộ xung nhịp truyền thông I2C | Chuẩn nhịp đồng hồ I2C Bus |

### 3. Lưu Ý Về Các Nhóm Chân Đặc Biệt Trên ESP32:
* **Nhóm chân Input-Only (GPIO 34, 35, 36, 39):** Chỉ có chức năng ngõ vào số hoặc tương tự, không có mạch đệm ngõ ra, không có điện trở kéo lên/kéo xuống nội bộ và không thể dùng làm ngõ ra PWM hay I2C.
* **Nhóm chân Cấu hình Khởi động (Strapping Pins - GPIO 0, 2):** Quyết định chế độ nạp chương trình (Bootloader) khi cấp nguồn. Hạn chế kết nối cảm biến trực tiếp vào các chân này để tránh xung đột trạng thái khởi động của vi điều khiển.

---

# TẦNG 4: CƠ CHẾ VẬN HÀNH NHÚNG CỦA ESP32

Chương trình điều khiển trong ESP32 hoạt động theo cơ chế **Lập lịch vòng tuần hoàn không khóa (Non-blocking Cyclic Polling)** kết hợp **Máy trạng thái hữu hạn (Finite State Machine - FSM)**:

### Chu Trình Định Thời Không Khóa Bằng `millis()`
Thay vì sử dụng hàm ngắt cứng `delay()` làm đóng băng toàn bộ tiến trình CPU, hệ thống sử dụng biến đếm thời gian thực `millis()`. Trong mỗi chu kỳ lặp `loop()`, hệ thống tuần tự thực thi 4 tiến trình:
1. **Tiến trình 1 - Quét trạng thái các ô đỗ (`readParking`):** Đọc tín hiệu số tại các chân GPIO 32, 33, 25, 26. Đếm số lượng cảm biến báo mức LOW để tính toán số chỗ đã sử dụng (`used`) và số vị trí còn trống (`freeSlots = 4 - used`).
2. **Tiến trình 2 - Máy trạng thái kiểm soát cổng (`controlGate` - FSM):**
   * *Trạng thái chờ (IDLE):* Khi phát hiện S1 = LOW và bãi còn chỗ (`freeSlots > 0`), chuyển trạng thái mở cổng VÀO. Khi phát hiện S2 = LOW, chuyển trạng thái mở cổng RA.
   * *Trạng thái mở cổng (GATE_OPENING / OPENED):* Phát xung PWM đưa Servo đến góc 90°.
   * *Trạng thái theo dõi hành lang (TRACKING):* Bật cờ ghi nhận khi phương tiện kích hoạt cảm biến thứ hai.
   * *Trạng thái đóng an toàn (CLEARANCE):* Khi cả hai cảm biến S1 và S2 cùng không còn vật cản liên tục quá 1.2 giây, phát xung PWM đưa Servo về góc 0° và đặt lại trạng thái chờ.
3. **Tiến trình 3 - Cập nhật giao diện cục bộ (`updateLCD`):** Định kỳ mỗi 500ms, làm mới dữ liệu về số lượng chỗ trống và địa chỉ IP kết nối lên màn hình LCD.
4. **Tiến trình 4 - Điều phối máy chủ mạng (`server.handleClient`):** Tiếp nhận và giải mã các truy vấn HTTP từ trình duyệt client, phản hồi dữ liệu JSON trạng thái hệ thống.

---

# TẦNG 5: PHƯƠNG PHÁP LUẬN CHẨN ĐOÁN SỰ CỐ & PHẢN BIỆN CHUYÊN MÔN

### Bảng Chẩn Đoán 5 Sự Cố Kỹ Thuật Điển Hình:
1. **Động cơ rung giật, vi điều khiển tự khởi động lại:** Sự cố sụt áp nguồn (Brownout). Giải pháp: Cấp nguồn 5V – 2A ngoài độc lập cho Servo và lắp tụ lọc 470µF – 1000µF.
2. **Vị trí đỗ trống nhưng hệ thống báo có xe:** Ngưỡng so sánh cảm biến quá nhạy, nhận tia phản xạ từ nền Fomex trắng. Giải pháp: Xoay biến trở trên mô-đun FC-51 ngược chiều kim đồng hồ để giảm độ nhạy.
3. **Màn hình LCD chỉ hiển thị các khối vuông đen:** Điện áp phân cực tương phản chưa tối ưu hoặc sai cấu hình địa chỉ bus I2C. Giải pháp: Tinh chỉnh chiết áp tương phản hoặc nạp chương trình quét địa chỉ I2C Scanner.
4. **Không kết nối được vào Web Server của ESP32:** Sai lệch mạng cục bộ hoặc điểm truy cập Wi-Fi kích hoạt tính năng cách ly client (AP Isolation). Giải pháp: Đảm bảo cùng kết nối mạng 2.4GHz hoặc chuyển sang chế độ softAP.
5. **Phương tiện đã qua cổng nhưng thanh chắn không hạ:** Cảm biến thứ hai chưa phát hiện được phương tiện do góc quét lệch hoặc khoảng cách lắp đặt quá xa. Giải pháp: Căn chỉnh lại hướng quang trục của đầu thu/phát hồng ngoại.

### Bộ Câu Hỏi Đánh Giá Bản Chất Kỹ Thuật:
* **Câu 1: "Tại sao lựa chọn vi điều khiển ESP32 thay cho dòng vi điều khiển 8-bit như ATmega328P (Arduino Uno)?"**  
  → ESP32 trang bị vi xử lý 32-bit lõi kép tốc độ 240MHz, dung lượng RAM lớn và tích hợp sẵn phần cứng Wi-Fi 802.11 b/g/n, cho phép vừa thực thi các tác vụ thời gian thực (đọc cảm biến, tạo xung PWM Servo) vừa vận hành đồng thời Web Server cổng 80 mà không gây tắc nghẽn luồng xử lý.
* **Câu 2: "Màu sắc của phương tiện ảnh hưởng như thế nào đến khả năng nhận diện của cảm biến hồng ngoại FC-51?"**  
  → Bề mặt màu sáng (trắng) có hệ số phản xạ tia hồng ngoại cao hơn bề mặt màu tối (đen). Do đó, khoảng cách phát hiện đối với vật thể màu đen sẽ ngắn hơn (khoảng 3 – 4 cm so với 7 – 10 cm của vật thể màu trắng). Cần căn chỉnh biến trở so sánh ở cự ly làm việc danh định (4 – 5 cm) để đảm bảo độ tin cậy nhận diện độc lập với màu sắc xe.
* **Câu 3: "Giải thuật xử lý thế nào khi hai phương tiện đồng thời tiếp cận cổng vào và cổng ra?"**  
  → Hệ thống hoạt động theo nguyên tắc ưu tiên ngắt logic theo thứ tự phát hiện của cảm biến nào kích hoạt trước. Do hạ tầng thiết kế là làn đường đơn, phương tiện đến sau bắt buộc phải nhường quyền lưu thông cho đến khi phương tiện thứ nhất hoàn tất chu trình thoát ly khỏi hành lang cổng.
* **Câu 4: "Phương án mở rộng kiến trúc để giám sát bãi đỗ xe qua mạng diện rộng (Internet / 4G)?"**  
  → Tích hợp giao thức truyền thông nhẹ **MQTT** kết nối đến máy chủ Cloud Broker (Adafruit IO, HiveMQ, EMQX) bằng cơ chế Publish/Subscribe, cho phép truyền nhận dữ liệu qua hạ tầng mạng di động mà không cần cấu hình NAT hoặc mở cổng (Port Forwarding) trên router mạng nội bộ.
* **Câu 5: "Định hướng phát triển nâng cao của đề tài?"**  
  → Tích hợp mô-đun thị giác máy tính ESP32-CAM ứng dụng giải thuật nhận diện quang học (AI/OCR) để tự động nhận dạng biển số phương tiện, đồng thời lưu trữ lịch sử ra vào trên cơ sở dữ liệu thời gian thực phục vụ công tác thống kê và tối ưu hóa hạ tầng.
