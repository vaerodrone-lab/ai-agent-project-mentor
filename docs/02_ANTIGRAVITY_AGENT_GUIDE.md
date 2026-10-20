# HƯỚNG DẪN SỬ DỤNG GOOGLE ANTIGRAVITY 2.0 LÀM TRỢ LÝ ĐỒ ÁN
> *Tận dụng tối đa sức mạnh của AI Agent thế hệ mới để hỗ trợ nghiên cứu, lập trình và hoàn thiện dự án.*

---

## 1. Google Antigravity Là Gì? Vì Sao Khác Biệt Với ChatGPT Thường?
* **ChatGPT / Chat thông thường:** Chỉ là cửa sổ chat đơn thuần. AI không nhìn thấy file trong máy tính, bạn phải tự copy code qua lại rất mất thời gian và dễ nhầm lẫn.
* **Google Antigravity (Antigravity 2.0):** Là môi trường **AI Agentic Coding (Trợ lý lập trình tự hành)**:
  * Agent có thể **đọc trực tiếp các file trong thư mục dự án**.
  * Agent có thể **tự động chỉnh sửa code**, kiểm tra cú pháp và chạy lệnh kiểm tra.
  * Agent có trí nhớ ngữ cảnh dự án sâu sắc thông qua các file quy tắc (`AGENT_INSTRUCTIONS.md`, `PROJECT_CONTEXT.md`).
  * Agent tự duy trì **nhật ký nghiên cứu (`WORK_LOG.md`)** và đồng bộ lên GitHub để mentor và các agent khác có thể tiếp nối hỗ trợ.

---

## 2. Cách Mở Và Kích Hoạt Dự Án Trên Antigravity 2.0

1. **Bước 1: Mở Thư Mục Dự Án**
   * Mở phần mềm Antigravity trên máy tính.
   * Chọn `File` &rarr; `Open Folder` &rarr; Trỏ tới thư mục `ai-agent-project-mentor`.
2. **Bước 2: Giao Tiếp Ban Đầu Với Agent**
   * Trong khung chat của Antigravity, gõ câu mở đầu:
     > *"Chào Agent! Mình là Mai Uyên. Mình vừa mở dự án Smart Parking. Bạn hãy đọc file `agent_workspace/AGENT_INSTRUCTIONS.md` và `agent_workspace/PROJECT_CONTEXT.md` để nắm bối cảnh, sau đó tóm tắt lại tiến độ hiện tại và hướng dẫn mình bước tiếp theo nhé!"*
3. **Bước 3: Agent Sẽ Tự Động Định Hình Vai Trò**
   * Agent sẽ đóng vai trò người gia sư (Socratic Mentor), hướng dẫn từng bước nhỏ, hỏi gợi mở tư duy chứ không làm thay.

---

## 3. Các Tình Huống Thực Tế Bạn Có Thể Nhờ Antigravity Giúp Đỡ

### 🛠️ Tình huống 1: Bắt Bệnh Phần Cứng & Code
* Khi nạp code gặp lỗi hoặc cảm biến không nhảy số:
  > *"Agent ơi, hiện tại mình cắm điện vào sa bàn nhưng màn hình LCD chỉ hiện 16 ô vuông đen sì. Dựa vào tài liệu chẩn đoán trong `docs/`, bạn hãy hướng dẫn mình 3 bước kiểm tra xem đang lỗi ở đâu?"*

### 💻 Tình huống 2: Đọc Hiểu Một Đoạn Code C++
* Khi bạn nhìn vào một hàm mà không hiểu nó làm gì:
  > *"Trong file `firmware/it.ino`, đoạn code từ dòng 60 đến 100 điều khiển barie đang hoạt động theo logic nào? Hãy giải thích cho mình bằng một ví dụ xe chạy qua cổng thực tế nhé."*

### 🎤 Tình huống 3: Luyện Tập Vấn Đáp Bảo Vệ Đồ Án
* Chuẩn bị trước ngày báo cáo với thầy cô:
  > *"Agent hãy đóng vai thầy giáo phản biện khó tính, đặt cho mình lần lượt 3 câu hỏi xoay quanh nguyên lý cảm biến và sụt áp nguồn. Sau khi mình trả lời, bạn hãy nhận xét xem câu trả lời của mình đã chuẩn kỹ thuật chưa và sửa giúp mình nhé!"*

### 📝 Tình huống 4: Cập Nhật Nhật Ký & Đẩy Code Lên GitHub
* Khi hoàn thành một buổi học hoặc sửa xong 1 tính năng:
  > *"Agent hãy tóm tắt những gì chúng ta vừa làm hôm nay vào file `agent_workspace/WORK_LOG.md` và tạo một commit git đẩy lên GitHub giúp mình nhé!"*
