# KỸ THUẬT RA LỆNH (PROMPT ENGINEERING) CHO SINH VIÊN KỸ THUẬT
> *Cách đặt câu hỏi chuẩn xác để nhận được câu trả lời sâu sắc, đúng trọng tâm và không bị lan man.*

---

## 1. Khung Cấu Trúc Đặt Lệnh Chuẩn Kỹ Thuật: C-T-C-O

Một prompt chất lượng cao luôn bao gồm 4 thành phần thiết yếu:

```
  ┌────────────────────────────────────────────────────────────────────────┐
  │ 1. CONTEXT (Bối cảnh): Bạn là ai, đang làm gì, phần cứng gồm những gì? │
  │ 2. TASK (Nhiệm vụ): Bạn muốn AI giải quyết việc gì cụ thể?             │
  │ 3. CONSTRAINT (Ràng buộc): Giới hạn về ngôn từ, phương pháp, cấm gì?   │
  │ 4. OUTPUT (Định dạng đầu ra): Bảng biểu, gạch đầu dòng, code kèm chú thích?│
  └────────────────────────────────────────────────────────────────────────┘
```

### So Sánh Ví Dụ Thực Tế:

* 🔴 **Prompt tồi (kém hiệu quả):**
  > *"Sửa lỗi giúp tôi cảm biến bãi xe bị lỗi."*
  > &rarr; *Hậu quả:* AI không biết bạn dùng cảm biến gì, vi điều khiển nào, bị lỗi gì, sẽ đoán mò và đưa ra câu trả lời chung chung vô dụng.

* 🟢 **Prompt xuất sắc (chuẩn CTCO):**
  > *"**[Context]** Tôi là sinh viên đang làm mô hình sa bàn bãi đỗ xe bằng ESP32 và 4 cảm biến hồng ngoại FC-51. Sa bàn làm bằng fomex trắng.  
  > **[Task]** Hiện tại trên Web đang báo cả 4 ô đều có xe dù bãi xe đang trống. Hãy phân tích nguyên nhân tại sao lại xảy ra hiện tượng này.  
  > **[Constraint]** Giải thích theo nguyên lý quang học và điện áp ngõ ra của IC LM393, không viết code vội, hãy hướng dẫn tôi 3 bước kiểm tra bằng mắt thường trước.  
  > **[Output]** Trình bày dạng bảng hoặc gạch đầu dòng ngắn gọn, dễ hiểu."*

---

## 2. Nghệ Thuật Đối Thoại Đa Tầng (Iterative Dialogue)

Không bao giờ dừng lại ở câu trả lời đầu tiên của AI. Hãy khai thác tối đa kiến thức bằng chuỗi câu hỏi tiếp nối:

1. **Tầng 1 (Hỏi bản chất):** *"Tại sao trong trường hợp này cảm biến lại kéo chân về 0V (LOW) thay vì 3.3V (HIGH)?"*
2. **Tầng 2 (Yêu cầu làm rõ bằng ví dụ):** *"Đoạn giải thích này hơi trừu tượng với tôi. Bạn có thể lấy một ví dụ đời thường để minh họa không?"*
3. **Tầng 3 (Thử thách & Tìm trường hợp biên - Edge Cases):** *"Nếu chiếc xe sơn màu đen nhám thì cảm biến này có phát hiện được không? Có giải pháp gì để khắc phục?"*
4. **Tầng 4 (Hỏi về an toàn phần cứng):** *"Nếu tôi cắm nhầm dây 5V vào chân GND thì linh kiện có bị cháy không? Làm sao nhận biết mạch đã an toàn?"*

---

## 3. Ba "Bùa Hộ Mệnh" Khi Trò Chuyện Với AI

* **Khi code quá dài và khó hiểu:**  
  &rarr; *"Hãy giải thích cho tôi thuật toán này theo dạng sơ đồ tuần tự 1 &rarr; 2 &rarr; 3 bằng tiếng Việt đời thường, khoan đưa ra code C++."*
* **Khi AI trả lời quá hàn lâm:**  
  &rarr; *"Hãy giải thích lại cho một sinh viên mới nhập môn từ số 0, tránh các thuật ngữ thanh ghi và ngắt phần cứng phức tạp."*
* **Khi cần chuẩn bị đi thi / bảo vệ:**  
  &rarr; *"Hãy đóng vai một giảng viên chấm thi nghiêm khắc, hỏi tôi 3 câu hỏi xoáy vào điểm yếu của mạch này và nhận xét câu trả lời của tôi."*
