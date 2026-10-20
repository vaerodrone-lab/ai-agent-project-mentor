# CẨM NANG VẬN HÀNH GOOGLE ANTIGRAVITY 2.0 (AI AGENTIC CODING)
> *Hướng dẫn thiết lập môi trường làm việc, quy chuẩn thư mục và quy trình tương tác cùng AI Agent trên máy tính cá nhân.*

---

## 1. QUY CHUẨN THIẾT LẬP THƯ MỤC TRÊN MÁY TÍNH (BẮT BUỘC)

Trước khi khởi động Antigravity, người học cần tuân thủ 3 quy tắc thiết lập đường dẫn để tránh lỗi trình biên dịch nhúng và Git:

### ⚠️ Quy tắc 1: Tuyệt đối không dùng tiếng Việt có dấu hoặc khoảng trắng
* **Lỗi thường gặp:** Đặt thư mục tại `Desktop` hoặc thư mục người dùng có dấu:  
  `C:\Users\Nguyễn Văn A\Desktop\Đồ Án IoT\...`
* **Hậu quả kỹ thuật:** Trình biên dịch C++ (xtensa-esp32-elf-gcc) của Arduino IDE và Git Bash sẽ báo lỗi không tìm thấy đường dẫn (Path Not Found) hoặc lỗi cú pháp không xác định.
* **Vị trí khuyến nghị:** Đặt tại thư mục ngắn gọn, không dấu:  
  `D:\projects\ai-agent-project-mentor` hoặc `C:\workspace\ai-agent-project-mentor`.

### ⚠️ Quy tắc 2: Giải nén đúng cấu trúc (Tránh lồng 2 tầng thư mục)
* Khi giải nén từ tệp ZIP, đảm bảo thư mục không bị nhân đôi dạng `ai-agent-project-mentor/ai-agent-project-mentor/...`.
* **Tiêu chí kiểm tra:** Khi mở thư mục dự án, bạn phải nhìn thấy ngay lập tức tệp `AGENTS.md`, `README.md`, `projects/` và `agent_rules/`.

### ⚠️ Quy tắc 3: Luôn mở đúng THƯ MỤC GỐC trên Antigravity
* Trong Antigravity: Chọn `File` &rarr; `Open Folder` &rarr; Trỏ tới đúng thư mục gốc `ai-agent-project-mentor`.
* **Tại sao:** Antigravity chỉ tự động nhận diện và kích hoạt tệp quy tắc nền tảng `AGENTS.md` khi bạn mở đúng thư mục gốc chứa tệp này. Nếu mở riêng thư mục con `projects/smart_parking`, Agent sẽ mất đi bộ quy chuẩn vận hành chung.

---

## 2. Antigravity 2.0 Là Gì? Sự Khác Biệt Với Chatbot Truyền Thống

* **Chatbot truyền thống (Cửa sổ chat độc lập):**
  * Không truy cập được hệ thống tệp cục bộ trên máy tính.
  * Đòi hỏi thao tác thủ công: sao chép mã nguồn qua lại giữa giao diện web và IDE nạp chip.
* **Google Antigravity 2.0 (Môi trường Lập trình Tự hành - Agentic IDE):**
  * **Trực tiếp đọc & ghi tệp:** Agent tự động đọc hiểu toàn bộ cấu trúc dự án, hỗ trợ sửa đổi mã nguồn và cập nhật tài liệu kỹ thuật trực tiếp trên máy tính.
  * **Tích hợp dòng lệnh (Integrated Terminal):** Agent có khả năng thực thi các tác vụ kiểm tra phiên bản, biên dịch và đồng bộ mã nguồn qua Git.
  * **Quản trị ngữ cảnh dài hạn:** Hệ thống quy chuẩn và nhật ký tiến độ được lưu trữ cục bộ, giúp Agent duy trì sự liên tục giữa các phiên làm việc.

---

## 3. Quy Trình Vận Hành Tiêu Chuẩn Trong Một Phiên Làm Việc

```
  [1. MỞ THƯ MỤC GỐC] ──► [2. GỬI MASTER PROMPT] ──► [3. TRIỂN KHAI THEO BƯỚC] ──► [4. LƯU LOG & PUSH GIT]
```

### Bước 1: Mở Workspace
* Khởi động phần mềm Google Antigravity trên máy tính.
* Chọn menu `File` &rarr; `Open Folder` &rarr; Trỏ tới thư mục gốc `ai-agent-project-mentor`.

### Bước 2: Đồng Bộ Ngữ Cảnh (Master Prompt)
* Mở tệp `ai_agent_methodology/TEMPLATES/MASTER_AGENT_INITIALIZE.md` (hoặc `agent_rules/MASTER_AGENT_PROMPT.md`).
* Sao chép toàn bộ nội dung Phần 1 và gửi vào khung trò chuyện của Antigravity.
* Agent sẽ lập tức nạp quy chuẩn hoạt động, tiếp nhận hiện trạng dự án và báo cáo sẵn sàng đồng hành.

### Bước 3: Triển Khai Nhiệm Vụ Kỹ Thuật Từng Bước
* Chia nhỏ vấn đề thành các tác vụ cụ thể: phân tích tín hiệu cảm biến, giải mã giải thuật FSM, cân chỉnh phần cứng.
* Luôn yêu cầu Agent phân tích nguyên lý trước khi chấp thuận chỉnh sửa mã nguồn.

### Bước 4: Ghi Nhận Lịch Sử & Đồng Bộ GitHub
* Kết thúc phiên làm việc, yêu cầu Agent:
  > *"Agent hãy tóm tắt các nội dung kỹ thuật vừa thực hiện vào `WORK_LOG.md` và hướng dẫn đồng bộ lên GitHub."*
* Mở Terminal và thực thi lệnh:
  ```bash
  git add .
  git commit -m "docs/fix: [Nội dung vừa hoàn thành]"
  git push origin main
  ```

---

## 4. Các Tính Năng Hỗ Trợ Kỹ Thuật Quan Trọng
* **Chế độ So Sánh Thay Đổi (Review Diffs):** Khi Agent đề xuất sửa đổi mã nguồn hoặc tài liệu, Antigravity hiển thị trực quan phần khác biệt (màu đỏ: nội dung cũ bị lược bỏ; màu xanh: nội dung mới được thêm). Người học cần rà soát trước khi chấp thuận (`Accept`).
* **Kéo thả hình ảnh thực nghiệm:** Người học có thể kéo thả trực tiếp ảnh chụp mạch điện, sa bàn hoặc kết quả đo đạc từ đồng hồ vạn năng vào khung chat để Agent hỗ trợ phân tích trực quan.
