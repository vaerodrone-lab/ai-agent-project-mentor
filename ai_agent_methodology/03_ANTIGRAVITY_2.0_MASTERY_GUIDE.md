# CẨM NANG LÀM CHỦ GOOGLE ANTIGRAVITY 2.0 (AI AGENTIC CODING)
> *Khai thác sức mạnh của Agent tự hành trên máy tính cá nhân để tăng tốc học tập gấp 5 lần.*

---

## 1. Antigravity 2.0 Là Gì? Tại Sao Khác Biệt Hoàn Toàn Với ChatGPT?

* **ChatGPT / Chatbot truyền thống (Cửa sổ chat đơn thuần):**
  * Bị cô lập: AI không nhìn thấy file trên ổ cứng, không biết trong thư mục có gì.
  * Thủ công: Bạn phải copy từng đoạn code dán vào chat, rồi lại copy từ chat dán ngược vào Arduino IDE.
* **Google Antigravity 2.0 (Môi trường Lập trình Tự hành - Agentic IDE):**
  * **Trực tiếp đọc & ghi file:** Agent có thể tự động mở file `.ino`, `.md`, `.html`, tự sửa lỗi và lưu trực tiếp trên máy bạn.
  * **Chạy lệnh tự động:** Agent có thể chạy terminal để kiểm tra file, dịch tài liệu, tạo file ZIP, commit và push code lên GitHub.
  * **Bộ nhớ ngữ cảnh dự án:** Nhờ hệ thống file quy tắc trong thư mục, Agent không bao giờ bị "quên" bối cảnh giữa chừng.

---

## 2. Quy Trình Làm Việc Tiêu Chuẩn Trong Một Phiên Antigravity

```
  [1. MỞ FOLDER] ───► [2. PASTE MASTER PROMPT] ───► [3. LÀM VIỆC THEO BƯỚC] ───► [4. YÊU CẦU AGENT GHI LOG & PUSH GIT]
```

### Bước 1: Mở Workspace
* Khởi động phần mềm Antigravity trên laptop.
* Chọn menu `File` &rarr; `Open Folder` &rarr; Trỏ tới thư mục dự án bạn đang làm.

### Bước 2: Dán Mẫu Prompt Khởi Tạo (Master Prompt)
* Mở file `ai_agent_methodology/TEMPLATES/MASTER_AGENT_INITIALIZE.md`.
* Copy toàn bộ nội dung và dán vào khung chat của Antigravity.
* Agent sẽ lập tức đọc toàn bộ quy tắc, cập nhật trạng thái dự án và đóng vai trò người gia sư gợi mở.

### Bước 3: Trao Đổi Từng Vấn Đề Cụ Thể
* Thực hiện từng tác vụ nhỏ: tìm hiểu cảm biến, giải mã đoạn code điều khiển barie, viết giao diện web...
* Luôn yêu cầu Agent giải thích trước khi cho phép Agent chỉnh sửa file code.

### Bước 4: Tự Động Lưu Vết & Đẩy Lên GitHub
* Trước khi tắt máy, chỉ cần gõ 1 câu lệnh ngắn gọn:
  > *"Agent hãy tóm tắt những gì chúng ta vừa làm hôm nay vào file `WORK_LOG.md` và push commit lên GitHub giúp mình nhé!"*
* Toàn bộ lịch sử sẽ được lưu trữ vĩnh viễn trên GitHub repo.

---

## 3. Các Phím Tắt & Tính Năng Hữu Ích Cần Biết
* **Chế độ Review Diffs (Xem thay đổi):** Khi Agent sửa code, Antigravity sẽ hiển thị màn hình so sánh 2 cột (bên trái là code cũ màu đỏ, bên phải là code mới màu xanh). Hãy nhìn lướt qua xem Agent đã thay đổi dòng nào trước khi chấp nhận.
* **Gửi ảnh sa bàn thực tế vào chat:** Bạn có thể kéo-thả ảnh chụp mạch điện thực tế vào khung chat để Agent nhìn và chẩn đoán chân cắm giúp bạn.
