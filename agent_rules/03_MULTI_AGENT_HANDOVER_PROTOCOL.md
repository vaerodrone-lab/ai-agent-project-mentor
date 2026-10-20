# GIAO THỨC BÀN GIAO VÀ TIẾP QUẢN DỰ ÁN GIỮA CÁC AGENT (MULTI-AGENT PROTOCOL)
> *Quy định dành cho bất kỳ AI Agent mới nào khi tham gia vào kho lưu trữ này.*

---

## 1. QUY TRÌNH 4 BƯỚC KHỞI ĐỘNG CỦA AGENT MỚI (ONBOARDING CHECKLIST)
Mỗi khi mentee mở một phiên chat mới hoặc một Agent mới được gọi vào workspace, Agent **BẮT BUỘC** phải tự thực hiện 4 bước sau trước khi trả lời câu hỏi đầu tiên của mentee:

```
  [1. ĐỌC RULES] ───► [2. ĐỌC CONTEXT & LOG] ───► [3. ĐỌC KHO TRI THỨC] ───► [4. CHÀO & XÁC NHẬN SẴN SÀNG]
```

* **Bước 1: Đọc thư mục nguyên tắc (`agent_rules/`)**
  * Đọc `01_CORE_OPERATING_PRINCIPLES.md` để nắm vững phong cách sư phạm gợi mở ("cho cần câu").
  * Đọc `02_KNOWLEDGE_LOGGING_AND_GIT_SYNC.md` để nắm nghĩa vụ ghi chép nhật ký và push Git.
* **Bước 2: Đọc bối cảnh và lịch sử gần nhất (`agent_workspace/`)**
  * Đọc `PROJECT_CONTEXT.md` để biết hiện trạng phần cứng và phần mềm.
  * Đọc 3 mục cuối cùng trong `WORK_LOG.md` để biết phiên trước mentee và Agent trước đã dừng lại ở đâu, còn tồn đọng việc gì.
* **Bước 3: Đọc kho kinh nghiệm tích lũy (`docs/EXPERIENCE_KNOWLEDGE_BASE.md`)**
  * Nắm rõ các lỗi phần cứng/phần mềm mà mentee đã từng gặp và cách đã giải quyết.
* **Bước 4: Chào mentee và tóm tắt ngắn gọn trạng thái tiếp quản**
  * Xuất câu chào thân thiện, tóm tắt 1 câu về việc đã nắm rõ bối cảnh và đề xuất bước hành động tiếp theo dựa trên mục tiêu còn dang dở trong `WORK_LOG.md`.

---

## 2. QUY TẮC BẢO TOÀN TÍNH NHẤT QUÁN CỦA MÃ NGUỒN VÀ TÀI LIỆU
* **Không đập đi xây lại:** Agent mới không được tự ý xóa bỏ cấu trúc code hoặc cách đặt tên biến/chân GPIO mà các Agent trước đã thống nhất với mentee, trừ khi có yêu cầu tái cấu trúc rõ ràng.
* **Bảo toàn chú thích (Comments Integrity):** Giữ nguyên các chú thích giải thích nguyên lý đời thường trong code để mentee dễ theo dõi.
* **Tôn trọng vai trò của Mentor con người:** Mentor con người là cố vấn chuyên môn cao nhất. Mọi định hướng lớn của Mentor đều là chỉ thị ưu tiên số 1 đối với Agent.
