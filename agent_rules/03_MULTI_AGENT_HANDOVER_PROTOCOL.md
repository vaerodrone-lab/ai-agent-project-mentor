# GIAO THỨC CHUYỂN GIAO & TIẾP NHẬN DỰ ÁN GIỮA CÁC AGENT (MULTI-AGENT PROTOCOL)
> *Quy chuẩn vận hành bắt buộc dành cho bất kỳ AI Agent nào khi khởi tạo hoặc tiếp quản phiên làm việc trong repository.*

---

## 1. QUY TRÌNH 4 BƯỚC KHỞI ĐỘNG (ONBOARDING PROTOCOL)
Khi người học bắt đầu một phiên làm việc mới hoặc triệu hồi một Agent vào workspace, Agent **BẮT BUỘC** thực hiện tuần tự 4 bước sau trước khi phản hồi yêu cầu kỹ thuật đầu tiên:

```
  [1. NẠP QUY TẮC NỀN TẢNG] ──► [2. NẠP CONTEXT & NHẬT KÝ] ──► [3. NẠP KHO TRI THỨC] ──► [4. BÁO CÁO TIẾP QUẢN]
```

* **Bước 1: Nạp quy chuẩn hoạt động (`agent_rules/` và `AGENTS.md`)**
  * Đọc `01_CORE_OPERATING_PRINCIPLES.md` để nắm phương pháp sư phạm gợi mở (Socratic Method) và tư duy thực chứng.
  * Đọc `02_KNOWLEDGE_LOGGING_AND_GIT_SYNC.md` để tuân thủ quy trình cập nhật nhật ký và đồng bộ Git.
* **Bước 2: Nạp hiện trạng và lịch sử kỹ thuật gần nhất (`projects/<ten_project>/workspace/`)**
  * Đọc `PROJECT_CONTEXT.md` để nắm vững cấu trúc phần cứng, ánh xạ chân tín hiệu và các vấn đề đang theo dõi.
  * Đọc các mục gần nhất trong `WORK_LOG.md` để xác định chính xác điểm dừng của phiên trước.
* **Bước 3: Nạp kho kinh nghiệm thực nghiệm (`projects/<ten_project>/docs/EXPERIENCE_KNOWLEDGE_BASE.md`)**
  * Nắm rõ danh mục các sự cố phần cứng/phần mềm đã được giải quyết để không đưa ra khuyến nghị trùng lặp hoặc mâu thuẫn.
* **Bước 4: Xác nhận tiếp quản và đề xuất lộ trình làm việc**
  * Phản hồi ngắn gọn xác nhận đã tiếp nhận đầy đủ ngữ cảnh và đề xuất bước triển khai tiếp theo dựa trên kế hoạch tồn đọng trong `WORK_LOG.md`.

---

## 2. NGUYÊN TẮC BẢO TOÀN KIẾN TRÚC MÃ NGUỒN VÀ DỮ LIỆU
* **Bảo toàn cấu trúc (Structural Continuity):** Không tự ý thay đổi quy ước đặt tên biến, cấu trúc hàm hoặc định nghĩa chân GPIO đã thống nhất trong các phiên trước trừ khi có yêu cầu tối ưu hóa cụ thể.
* **Bảo toàn tính toàn vẹn của chú thích (Comments Integrity):** Giữ nguyên các chú giải kỹ thuật nhằm phục vụ mục tiêu học tập và giải trình bản chất của người học.
* **Ưu tiên định hướng của Mentor:** Ý kiến và chỉ đạo chuyên môn của Mentor là căn cứ tham chiếu kỹ thuật cao nhất trong toàn bộ hệ thống.
