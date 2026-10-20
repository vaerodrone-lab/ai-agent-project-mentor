# PHƯƠNG PHÁP 4 BƯỚC BẮT BỆNH PHẦN CỨNG & PHẦN MỀM CÙNG AI
> *Tư duy loại trừ khoa học: Không đoán mò, tìm đúng nguyên nhân gốc rễ.*

---

## 1. Bản Chất Của Lỗi Kỹ Thuật: Luôn Có Nguyên Nhân Vật Lý Rõ Ràng

Trong các dự án kỹ thuật (đặc biệt là IoT), khi mạch không chạy, 90% người mới bắt đầu sẽ cuống cuồng sửa code. Tuy nhiên, thực tế thống kê cho thấy:
* **60% lỗi nằm ở Nguồn điện & Dây cắm vật lý** (lỏng dây, thiếu dòng, sụt áp).
* **25% lỗi nằm ở Môi trường & Linh kiện** (độ nhạy biến trở, nhiễu ánh sáng, đứt linh kiện).
* **Chỉ có 15% lỗi thực sự nằm ở Code logic**.

Vì vậy, bạn phải rèn luyện phương pháp tư duy kiểm tra theo **Tháp 4 Tầng từ dưới lên**:

```
  ▲  [TẦNG 4: CODE LOGIC] ──────────► Đúng điều kiện if/else, đúng chân GPIO chưa?
  │  [TẦNG 3: MỨC TÍN HIỆU LOGIC] ──► Đèn LED trên module có đổi trạng thái không?
  │  [TẦNG 2: TIẾP XÚC VẬT LÝ] ────► Dây cắm có lỏng không, cắm đúng chân chưa?
  │  [TẦNG 1: NGUỒN ĐIỆN VẬT LÝ] ───► Có đủ 5V không? Dòng có bị tụt khi motor quay không?
```

---

## 2. Quy Trình 4 Bước Phối Hợp Cùng AI Để Bắt Bệnh

### Bước 1: Thu Thập Triệu Chứng Vật Lý Bằng Mắt Thường
Trước khi hỏi AI, bạn phải là "tai mắt" của AI tại hiện trường. Hãy quan sát và ghi chép:
* Đèn nguồn (Power LED) trên bo ESP32 và cảm biến có sáng không? Sáng mạnh hay mờ?
* Khi đưa vật cản lại gần, đèn báo tín hiệu (Detect LED) có đổi màu không?
* Động cơ Servo có bị rung giật, phát ra tiếng kêu rè rè hay không?
* Màn hình LCD có hiện chữ không hay chỉ sáng đèn nền?

### Bước 2: Cung Cấp Triệu Chứng Đầy Đủ Cho AI (Kèm Bảng Pinout)
Gửi prompt cho AI theo công thức:
> *"Mạch của tôi gặp hiện tượng [mô tả triệu chứng ở Bước 1]. Tôi đang cắm cảm biến vào chân [GPIO x] và Servo vào chân [GPIO y]. Dựa vào hiện tượng này, hãy liệt kê cho tôi 3 nguyên nhân khả dĩ nhất theo thứ tự từ Nguồn điện &rarr; Dây cắm &rarr; Code."*

### Bước 3: Kiểm Chứng Từng Giả Thuyết (Phương Pháp Loại Trừ)
* AI sẽ đưa ra các giả thuyết (ví dụ: Giả thuyết 1: sụt áp; Giả thuyết 2: ngược logic; Giả thuyết 3: biến trở nhạy).
* **Quy tắc vàng:** Chỉ thay đổi **DUY NHẤT 1 YẾU TỐ** tại một thời điểm để kiểm tra.
  * Nếu xoay biến trở &rarr; Thử nghiệm ngay. Không vừa xoay biến trở vừa sửa code vừa đổi dây, vì nếu chạy được bạn cũng không biết do đâu mà hết lỗi!

### Bước 4: Lưu Lại Thẻ Bài Học Kinh Nghiệm
Khi đã xử lý xong lỗi, yêu cầu AI:
> *"Chúng ta vừa xử lý thành công lỗi này. Hãy cùng tôi viết lại một thẻ kinh nghiệm ngắn gọn (gồm Hiện tượng &rarr; Nguyên nhân &rarr; Cách khắc phục) vào file `EXPERIENCE_KNOWLEDGE_BASE.md` để lần sau gặp lại tôi xử lý được ngay trong 1 phút."*
