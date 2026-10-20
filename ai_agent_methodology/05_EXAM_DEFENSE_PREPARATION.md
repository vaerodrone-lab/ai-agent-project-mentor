# CÁCH SỬ DỤNG AI ĐỂ LUYỆN TẬP VẤN ĐÁP BẢO VỆ ĐỒ ÁN ĐIỂM 9 - 10
> *Biến AI thành "Giám khảo khó tính" để tự tin đối đáp trước mọi câu hỏi phản biện của hội đồng.*

---

## 1. Bí Mật Đằng Sau Tiêu Chí Đánh Giá Của Thầy Cô (Rubric 6)

Khi chấm thi hoặc đánh giá đồ án kết thúc học phần, các giảng viên đại học **không chỉ xem mô hình có chạy được hay không**. Thầy cô sẽ đánh giá:
1. **Bạn có thực sự hiểu bản chất thiết kế không?** (Hay là copy code trên mạng hoặc nhờ người khác làm hộ?).
2. **Khả năng làm chủ và tư duy kỹ thuật:** Bạn có giải thích được tại sao lại chọn linh kiện này, tại sao lại dùng giao thức kia?
3. **Tác phong đĩnh đạc và câu trả lời súc tích:** Trả lời đúng trọng tâm trong 2 – 3 câu, không nói vòng vo, tự tin.

---

## 2. Kịch Bản 3 Vòng Luyện Tập Vấn Đáp Cùng AI

Bạn có thể mở Antigravity lên và yêu cầu Agent huấn luyện theo 3 vòng sau:

### 🥊 Vòng 1: Đóng Vai Giám Khảo Khảo Sát Phần Cứng
* **Câu lệnh (Prompt):**
  > *"Bây giờ bạn hãy đóng vai một thầy giáo chấm thi đồ án IoT. Hãy đặt cho tôi lần lượt 3 câu hỏi liên quan đến việc chọn linh kiện, nguyên lý cảm biến và sơ đồ đấu nối chân trên mạch bãi đỗ xe. Hỏi từng câu một, sau khi tôi gõ câu trả lời thì bạn hãy nhận xét và sửa lại cho chuẩn mực nhé!"*

### 🥊 Vòng 2: Đóng Vai Giám Khảo Xoáy Vào Giải Thuật & An Toàn
* **Câu lệnh (Prompt):**
  > *"Tiếp tục đóng vai giám khảo, hãy hỏi xoáy vào logic điều khiển của tôi: Làm sao phân biệt xe vào/ra? Nếu có xe dừng giữa cổng thì barie có đè vào xe không? Tại sao dùng millis() mà không dùng delay()? Hãy hỏi tôi và chấm điểm câu trả lời của tôi theo thang điểm 10."*

### 🥊 Vòng 3: Đóng Vai Giám Khảo Mở Rộng Kiến Thức Đám Mây & AI
* **Câu lệnh (Prompt):**
  > *"Hãy hỏi tôi 2 câu hỏi mở rộng về tương lai của đồ án: Làm thế nào để đưa dữ liệu lên Cloud xem qua 4G bằng MQTT? Làm thế nào để tích hợp camera AI nhận diện biển số xe? Hướng dẫn tôi cách trả lời để hội đồng thấy tôi có tầm nhìn công nghệ tốt nhất."*

---

## 3. Công Thức Trả Lời Vấn Đáp 3 Bước (Chuẩn Phong Thái Kỹ Sư)

Mỗi khi thầy cô đặt câu hỏi, hãy bình tĩnh hít một hơi thật sâu và trả lời theo công thức:

```
  [1. XÁC NHẬN BẢN CHẤT]  ───►  [2. GIẢI THÍCH NGUYÊN LÝ]  ───►  [3. CHỨNG MINH THỰC TẾ TRÊN MÔ HÌNH]
```

* **Ví dụ:** Thầy cô hỏi: *"Cảm biến này nhận diện xe màu đen có bị ảnh hưởng không?"*
  * **Bước 1 (Xác nhận):** *"Dạ thưa Thầy/Cô, có bị ảnh hưởng ạ."*
  * **Bước 2 (Nguyên lý):** *"Vì cảm biến hoạt động theo nguyên lý quang học phát xạ và phản xạ hồng ngoại. Xe màu đen hấp thụ tia hồng ngoại nhiều hơn xe màu sáng nên cự ly nhận diện sẽ ngắn lại khoảng 2 – 3 cm."*
  * **Bước 3 (Thực tế):** *"Để giải quyết, trên mô hình em đã vi chỉnh biến trở ngưỡng so sánh ở cự ly trung bình 4 cm, đảm bảo xe màu đen hay màu trắng lùi vào ô đều kích hoạt mức LOW chính xác ạ."*
* &rarr; *Thầy cô nghe câu trả lời này chắc chắn sẽ chấm điểm A tuyệt đối vì bạn nắm rất chắc bản chất!*
