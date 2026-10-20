# CẨM NANG KỸ THUẬT: HIỂU TRỌN VẸN HỆ THỐNG BÃI ĐỖ XE THÔNG MINH TỪ A ĐẾN Z
> **Định hướng tài liệu:** Bóc tách bản chất phần cứng, dòng chảy tín hiệu và giải thuật vận hành nhúng của hệ thống Bãi đỗ xe thông minh (Smart Parking System).
> 
> **Lộ trình 5 tầng tư duy:**
> 1. **Tầng 1: Giải Phẫu Mô Hình Thực Tế** (Quan sát trực diện sa bàn, điểm danh 4 khu vực).
> 2. **Tầng 2: 5 Bài Toán Thực Tế & Cách Hệ Thống Giải Quyết** (Tư duy nhân quả: Vấn đề $\rightarrow$ Linh kiện giải quyết).
> 3. **Tầng 3: Bản Đồ Kết Nối** (Phân định Hệ nuôi sống & Hệ thần kinh, bảng pinout, các chân đặc biệt).
> 4. **Tầng 4: Bộ Não ESP32 Đang "Nghĩ" Gì Từng Giây?** (Giải mã logic tuần tra FSM không khóa `millis()`).
> 5. **Tầng 5: Cẩm Nang Bắt Bệnh Thực Địa & Giải Trình Bản Chất** (Chẩn đoán 5 sự cố & Bộ câu hỏi cốt lõi).

---

# TẦNG 1: GIẢI PHẪU MÔ HÌNH THỰC TẾ TRÊN SA BÀN

Quan sát trực tiếp mô hình sa bàn fomex trắng của đề tài, toàn bộ hệ thống được chia thành 4 khu vực chức năng rõ rệt:

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

### Bảng Giải Phẫu Chi Tiết 4 Khu Vực:
1. **[1] Góc Dưới Bên Trái (Trung tâm điều khiển & Nguồn):** Bo mạch vi điều khiển ESP32 gắn trên perfboard kèm jack DC và mạch nguồn ổn áp. Đóng vai trò là **Bộ não trung tâm**: tiếp nhận dây tín hiệu từ cảm biến, thực thi thuật toán và phát sóng Wi-Fi.
2. **[2] Dãy Bên Phải (Khu vực 4 ô đỗ xe):** 04 cảm biến quang hồng ngoại FC-51 gắn đối diện các vách ngăn chéo (đánh số 1, 2, 3, 4). Đóng vai trò là **Trạm giám sát vị trí**: khi có xe lùi vào, cảm biến phát hiện và báo về bộ não để ghi nhận ô đó đã có xe.
3. **[3] Lối Vào / Ra Bên Trái (Trạm kiểm soát cổng):** Động cơ Servo MG90S màu đỏ gắn thanh barie xốp trắng, kết hợp 2 cảm biến hồng ngoại S1 (ngoài) và S2 (trong). Đóng vai trò là **Cổng chắn tự động hai chiều**: nhận diện hướng xe vào/ra và canh chừng đuôi xe để hạ cần barie an toàn.
4. **[4] Phía Dưới Cổng Chắn (Bảng thông báo cục bộ):** Màn hình LCD 1602 xanh lá có gắn chip I2C phía sau. Đóng vai trò là **Bảng điện tử hướng dẫn tài xế**: hiển thị IP kết nối Wi-Fi, số lượng xe trong bãi và số vị trí còn trống.

---

# TẦNG 2: 5 BÀI TOÁN THỰC TẾ & CÁCH HỆ THỐNG GIẢI QUYẾT

Thay vì học thuộc lòng thông số linh kiện, hãy cùng phân tích xem kỹ sư gặp phải những bài toán thực tế nào và lựa chọn linh kiện để giải quyết ra sao:

### 📌 Bài toán 1: Làm sao máy móc biết một ô đang có xe đỗ hay đang trống?
* **Thách thức:** Vi điều khiển chỉ là con chip silicon vô tri, không có mắt để nhìn như con người. Làm sao chuyển sự hiện diện vật lý của chiếc xe thành tín hiệu điện?
* **Giải pháp kỹ thuật: Cảm biến Quang Hồng Ngoại FC-51.**
  * *Nguyên lý phát – thu:* Module có 1 đèn LED liên tục phát ra chùm tia hồng ngoại vô hình (~940nm). Bên cạnh là một mắt thu quang học (Photodiode).
  * *Khi ô trống:* Chùm tia hồng ngoại phóng thẳng vào không gian và mất đi $\rightarrow$ Mắt thu không nhận được tín hiệu.
  * *Khi có xe đỗ:* Thân xe chặn đường đi của tia sáng, làm ánh sáng hồng ngoại dội ngược lại mắt thu.
  * *Trọng tài so sánh LM393:* Ánh sáng dội lại tạo ra điện áp rơi trên mắt thu. IC so sánh LM393 so sánh điện áp này với ngưỡng chuẩn do biến trở quy định:
    * Có xe: LM393 kéo chân OUT xuống mass (**Mức LOW = 0V**).
    * Không có xe: Chân OUT giữ ở nguồn dương (**Mức HIGH = 3.3V / 5V**).
* **Bản chất cần nhớ:** Chân cảm biến xuất mức **LOW nghĩa là CÓ XE**, mức **HIGH nghĩa là TRỐNG**. Biến trở xoay màu xanh dùng để vi chỉnh cự ly bắt gần/xa.

---

### 📌 Bài toán 2: Chỉ có 1 làn đường, làm sao biết xe đang VÀO hay đang RA?
* **Thách thức:** Nếu chỉ đặt 1 cảm biến tại cổng, nó chỉ biết "có xe", nhưng không biết xe muốn vào hay muốn ra để quyết định mở cổng và kiểm tra số chỗ trống.
* **Giải pháp kỹ thuật: Đặt 2 Trạm Gác Nối Tiếp (Cảm biến S1 ngoài và S2 trong).**
  * Thanh barie được đặt ở chính giữa. Cảm biến S1 đặt ở phía đường bên ngoài; cảm biến S2 đặt ở phía trong bãi đỗ.
  * *Xe VÀO:* Xe đi từ ngoài vào bắt buộc phải chạm **S1 trước**. Khi S1 báo LOW mà S2 vẫn HIGH, bộ não xác nhận: *"Phương tiện đang xin VÀO"*. Nếu bãi còn chỗ trống (`freeSlots > 0`), cổng sẽ mở.
  * *Xe RA:* Xe từ trong bãi đi ra bắt buộc phải chạm **S2 trước**. Khi S2 báo LOW mà S1 vẫn HIGH, bộ não xác nhận: *"Phương tiện đang xin RA"*. Cổng lập tức mở cho xe rời bãi mà không cần kiểm tra số chỗ.
* **Bản chất cần nhớ:** Đây gọi là thuật toán *Trình tự kích hoạt theo thời gian (Sequential Triggering)*. Thứ tự chạm trạm gác trước/sau sẽ quyết định chiều chuyển động của phương tiện.

---

### 📌 Bài toán 3: Làm sao đóng/mở cổng chính xác và không đè vào nóc xe?
* **Thách thức:** Động cơ thông thường bật điện là quay tít mù, không thể dừng đúng góc 90°. Ngoài ra nếu xe đang đi qua mà cổng vội vàng hạ xuống sẽ đè bẹp nóc xe!
* **Giải pháp kỹ thuật: Động cơ Servo MG90S + Cơ chế an toàn 2 lớp (Clearance & Timeout).**
  * *Điều khiển góc chính xác bằng xung PWM:* Động cơ Servo có mạch so sánh góc và biến trở hồi tiếp bên trong. ESP32 phát xung vuông chu kỳ 20ms: xung rộng 0.5ms barie hạ về góc 0° (Đóng), xung rộng 1.5ms barie nhấc lên góc 90° (Mở). Chọn loại MG90S bánh răng kim loại để chống trượt ren.
  * *Cơ chế an toàn chống kẹp xe:* Khi barie đang mở, xe chạy qua cổng sẽ kích hoạt cảm biến thứ hai (xác nhận xe đã lọt vào khu vực cổng). Cổng **chỉ bắt đầu đóng** khi thỏa mãn đồng thời:
    1. Cả 2 cảm biến S1 và S2 cùng không còn vật cản (xe đã đi khuất hẳn).
    2. Trạng thái thông thoáng này phải duy trì liên tục quá **1.2 giây (Clearance Time)** để đuôi xe qua hẳn tầm quét của thanh chắn.
    3. Nếu xe dừng lại ngập ngừng che một trong hai mắt, đồng hồ đếm lại từ đầu!

---

### 📌 Bài toán 4: Màn hình LCD cần 16 dây, làm sao thu gọn xuống 2 dây?
* **Thách thức:** ESP32 có giới hạn số chân cắm. Nếu màn hình LCD 1602 ngốn mất 16 chân thì hệ thống không còn chân nào để cắm 6 cảm biến và Servo.
* **Giải pháp kỹ thuật: Tích hợp Chip chuyển đổi giao tiếp I2C (PCF8574).**
  * Mặt sau màn hình được hàn sẵn bo mạch mang chip PCF8574 (địa chỉ mặc định `0x27`).
  * ESP32 chỉ cần dùng 2 sợi dây: dây **SDA (GPIO 21)** để bắn dữ liệu nối tiếp từng bit một, và dây **SCL (GPIO 22)** để tạo nhịp đập đồng hồ.
  * Chip PCF8574 nhận dữ liệu 2 dây đó rồi tự bung ra 16 chân điều khiển màn hình LCD hiển thị chữ số.

---

### 📌 Bài toán 5: Làm sao điện thoại xem được bãi xe mà không cần kéo dây mạng?
* **Thách thức:** Muốn giám sát bãi xe từ xa bằng smartphone nhưng không muốn mua module mạng cồng kềnh hay kéo dây LAN.
* **Giải pháp kỹ thuật: Khai thác sức mạnh Wi-Fi và Web Server tích hợp của ESP32.**
  * ESP32 là vi điều khiển IoT có sẵn bộ thu phát sóng vô tuyến Wi-Fi 2.4GHz bên trong chip. Chương trình khởi tạo một máy chủ Web (Web Server) ở cổng 80:
    * Khi điện thoại mở trình duyệt gõ địa chỉ IP của ESP32 $\rightarrow$ ESP32 gửi trang Web HTML/CSS về điện thoại.
    * Cứ mỗi 1 giây, mã JavaScript trên điện thoại tự gửi lệnh ngầm `fetch('/data')` để hỏi ESP32: *"Bãi xe bây giờ thế nào?"*. ESP32 trả lời bằng một chuỗi văn bản JSON ngắn gọn: `{"used": 2, "free": 2, "slots": [...]}`, trình duyệt tự đổi màu ô xe xanh/đỏ tức thì.

---

# TẦNG 3: BẢN ĐỒ KẾT NỐI (DÒNG NĂNG LƯỢNG & DÒNG TÍN HIỆU)

Toàn bộ hệ thống thực chất chỉ gồm đúng **2 mạng lưới dây duy nhất**:

### 1. Hệ Nuôi Sống (Mạng Nguồn Điện) & Hiện Tượng Sụt Áp
* Dây đỏ (+5V) và Dây đen (GND) cấp điện cho mọi module.
* **Nguyên lý sụt áp (Brownout Reset):** Động cơ Servo MG90S khi khởi động có thể giật một dòng điện đột biến lên tới gần 1A (Stall Current). Nếu cắm nguồn Servo chung với chân 3.3V của ESP32, động cơ sẽ kéo tụt điện áp đường nguồn nuôi chip, làm ESP32 tự reset liên tục.
* **Quy tắc an toàn:** Cấp nguồn 5V riêng cho Servo từ mạch hạ áp nguồn ngoài, đồng thời bắt buộc phải **nối chung chân mass (GND)** giữa nguồn ngoài và ESP32.

### 2. Hệ Thần Kinh (Mạng Dây Tín Hiệu) & Bảng Pinout Tra Cứu

| Chân ESP32 | Tên linh kiện | Ý nghĩa tín hiệu đời thực | Mức logic quy ước |
| :---: | :--- | :--- | :--- |
| **GPIO 27** | Cảm biến cổng ngoài (S1) | Báo có xe đang chờ vào cổng | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 14** | Cảm biến cổng trong (S2) | Báo có xe chuẩn bị ra / đã lọt qua cổng | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 32** | Cảm biến Ô số 1 | Báo trạng thái chiếm chỗ ô 1 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 33** | Cảm biến Ô số 2 | Báo trạng thái chiếm chỗ ô 2 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 25** | Cảm biến Ô số 3 | Báo trạng thái chiếm chỗ ô 3 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 26** | Cảm biến Ô số 4 | Báo trạng thái chiếm chỗ ô 4 | `LOW = Có xe` \| `HIGH = Trống` |
| **GPIO 18** | Dây cam Servo MG90S | Đưa xung PWM lệnh quay cần barie | `Xung 0.5ms = 0°` \| `Xung 1.5ms = 90°` |
| **GPIO 21** | Chân SDA của LCD | Bắn chuỗi bit dữ liệu hiển thị chữ | I2C Data Bus (Chuỗi bit nối tiếp) |
| **GPIO 22** | Chân SCL của LCD | Tạo nhịp đập đồng hồ truyền tin | I2C Clock Bus (Xung nhịp chuẩn) |

### 3. Phân Biệt Các Chân Đặc Biệt Của ESP32:
* **Chân Input-Only (GPIO 34, 35, 36, 39):** Chỉ làm ngõ vào, không thể xuất tín hiệu điều khiển Servo hay I2C, không có điện trở kéo lên nội.
* **Chân Strapping Pins (GPIO 0, 2):** Ảnh hưởng chế độ Bootloader khi nạp code, không nên nối cảm biến vào để tránh kẹt chip khi bật nguồn.

---

# TẦNG 4: BỘ NÃO ESP32 ĐANG "NGHĨ" GÌ TỪNG GIÂY?

Không cần đọc hiểu code C++, toàn bộ chương trình trong ESP32 hoạt động hệt như một **"Người bảo vệ tự động đi tuần tra"**:

### Chu Trình Tuần Tra Không Khóa (Non-Blocking Loop)
Dùng `millis()` bấm giờ thay vì `delay()`. Cứ mỗi 20 mili-giây, bác bảo vệ lặp lại tuần hoàn 4 hành động:
1. **Hành động 1 - Quét 4 ô đỗ (`readParking`):** Đọc chân 32, 33, 25, 26. Đếm số ô báo LOW $\rightarrow$ tính ra `used` và `freeSlots = 4 - used`.
2. **Hành động 2 - Xử lý cổng ra vào (`controlGate` - Máy Trạng Thái FSM):**
   * *Xe ngoài cổng (S1 LOW, S2 HIGH):* Nếu `freeSlots > 0` $\rightarrow$ Mở barie góc 90°. Nếu `freeSlots == 0` $\rightarrow$ Giữ nguyên cổng đóng!
   * *Xe trong bãi (S2 LOW, S1 HIGH):* Mở barie ngay lập tức cho xe ra.
   * *Xe đang qua cổng:* Kích hoạt cảm biến thứ hai $\rightarrow$ Bật cờ `passedSecondSensor = true`.
   * *Đóng cổng an toàn:* Cả 2 cảm biến cùng không còn vật cản liên tục quá 1.2 giây $\rightarrow$ Quay Servo về góc 0° hạ barie.
3. **Hành động 3 - Viết lên bảng LCD (`updateLCD`):** Cứ mỗi 500ms cập nhật số lượng xe và chỗ trống lên màn hình.
4. **Hành động 4 - Trả lời máy chủ Web (`server.handleClient`):** Nếu có điện thoại gửi yêu cầu GET `/data`, lập tức phản hồi chuỗi JSON trạng thái.

---

# TẦNG 5: CẨM NANG BẮT BỆNH THỰC ĐỊA & GIẢI TRÌNH BẢN CHẤT

### Bảng Chẩn Đoán 5 Sự Cố Kinh Điển:
1. **Servo giật liên tục, ESP32 reset:** Lỗi sụt áp nguồn (Brownout). Cần dùng nguồn ngoài 5V – 2A và hàn thêm tụ lọc 470uF.
2. **Ô đỗ trống nhưng đèn báo có xe:** Độ nhạy cảm biến quá cao, bắt ánh sáng sàn. Lấy vít xoay biến trở ngược chiều kim đồng hồ để giảm nhạy.
3. **Màn hình LCD hiện 16 ô vuông đen:** Chưa chỉnh biến trở tương phản sau lưng màn hình, hoặc sai địa chỉ I2C (cần nạp I2C Scanner).
4. **Điện thoại không vào được Web:** Lệch mạng Wi-Fi hoặc Router bật AP Isolation. Cần kết nối cùng Wi-Fi và gõ đúng địa chỉ IP trên LCD.
5. **Xe qua cổng nhưng barie không hạ:** Cảm biến thứ hai chưa quét trúng thân xe nên cờ hiệu chưa bật. Cần căn chỉnh lại góc nghiêng của mắt cảm biến.

### Bộ 5 Câu Hỏi Trả Lời Bản Chất:
* **Câu 1: "Tại sao dùng ESP32 mà không dùng Arduino Uno?"** $\rightarrow$ ESP32 là chip 32-bit lõi kép 240MHz, RAM lớn và tích hợp sẵn Wi-Fi, chạy song song vừa quét cảm biến vừa làm Web Server mà không bị treo.
* **Câu 2: "Cảm biến hồng ngoại nhận diện xe màu trắng và màu đen có khác nhau không?"** $\rightarrow$ Có. Màu trắng phản xạ ánh sáng mạnh hơn (bắt xa 7-10cm), màu đen hấp thụ nhiều hơn (bắt gần 3-4cm). Ta chỉ cần vi chỉnh biến trở ở cự ly trung bình 4-5cm để xe nào cũng nhận diện chính xác.
* **Câu 3: "Hai xe cùng lao vào cổng một lúc thì sao?"** $\rightarrow$ Hệ thống ưu tiên xe nào kích hoạt cảm biến trước. Làn đường đơn bắt buộc xe đến sau phải chờ xe đến trước thoát ly hoàn toàn.
* **Câu 4: "Muốn xem bãi xe từ xa qua 4G thì làm thế nào?"** $\rightarrow$ Dùng giao thức MQTT đưa dữ liệu lên máy chủ Đám mây (Cloud Broker như Adafruit IO, HiveMQ, Blynk) để truy cập mọi nơi qua Internet.
* **Câu 5: "Hướng nâng cấp tiếp theo?"** $\rightarrow$ Gắn camera ESP32-CAM nhận diện biển số xe bằng AI (ALPR) và lưu trữ dữ liệu lịch sử để dự báo giờ cao điểm.
