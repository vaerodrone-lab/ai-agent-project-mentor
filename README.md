# NỀN TẢNG MENTORING ĐỒ ÁN VÀ KHUNG PHƯƠNG PHÁP LUẬN CỘNG TÁC AI TRONG NGHIÊN CỨU KỸ THUẬT
*(Engineering Mentorship Platform & Agentic AI Research Framework)*

> **Đơn vị phát triển:** Vaerodrone Lab  
> **Repository:** `vaerodrone-lab/ai-agent-project-mentor`  
> **Phạm vi ứng dụng:** Đào tạo phương pháp luận nghiên cứu, phát triển đồ án kỹ thuật liên ngành (IoT / Hệ thống nhúng) và chuẩn hóa mô hình cộng tác cùng AI Agent (Google Antigravity 2.0).

---

## 🎯 Định Hướng Đào Tạo & Nguyên Tắc Phương Pháp Luận

Kho lưu trữ được xây dựng nhằm thiết lập **môi trường đào tạo năng lực tự chủ kỹ thuật và phương pháp giải quyết vấn đề khoa học cho người học**. Hệ thống chuẩn hóa mô hình tương tác cùng trí tuệ nhân tạo thế hệ mới (Agentic AI) dựa trên các nguyên tắc cốt lõi:

1. **Phát triển năng lực tự chủ (Autonomous Competency Development):**  
   Chuyển đổi từ mô hình tiếp nhận giải pháp thụ động sang mô hình cộng tác tư duy chủ động (*Co-thinking & Verification*). Người học trực tiếp làm chủ kiến trúc hệ thống, phân tích bản chất vật lý của linh kiện, giải mã lưu đồ thuật toán và thực chứng trên mô hình thực nghiệm.

2. **Chuẩn hóa quy trình kỹ thuật & Quản trị tri thức (Knowledge Management & Traceability):**  
   Mọi giai đoạn nghiên cứu, chẩn đoán sự cố phần cứng/phần mềm và trích xuất kinh nghiệm thực tế đều được văn bản hóa có cấu trúc và quản lý phiên bản nghiêm ngặt thông qua Git.

3. **Mô hình hóa khung phương pháp luận đa dự án (Cross-Project Reusability):**  
   Cung cấp cấu trúc phương pháp luận độc lập (`ai_agent_methodology/`), có khả năng mở rộng và áp dụng nhất quán cho các đồ án chuyên ngành và đề tài nghiên cứu tiếp theo.

---

## 📂 Kiến Trúc Hệ Thống Kho Lưu Trữ

```
ai-agent-project-mentor/
├── AGENTS.md                                # Quy tắc nền tảng tự động nạp cho Antigravity 2.0
├── README.md                                # Tài liệu tổng quan kiến trúc và hướng dẫn vận hành
├── kich_hoat_dong_bo_github.bat             # Công cụ tự động kết nối và xác thực GitHub 1-click
│
├── 🧠 ai_agent_methodology/                 # KHUNG PHƯƠNG PHÁP LUẬN DÙNG CHUNG CHO MỌI ĐỀ TÀI
│   ├── README.md                            # Tổng quan khung phương pháp luận
│   ├── 00_THEORETICAL_FOUNDATIONS_RESEARCH.md # Báo cáo nghiên cứu: Khoa học nhận thức, Tâm lý học & Sư phạm AI
│   ├── 01_AI_COLLABORATION_MINDSET.md       # Tư duy cộng tác: Mô hình đối tác tư duy (Co-thinker)
│   ├── 02_PROMPT_ENGINEERING_FOR_STUDENTS.md   # Kỹ thuật xây dựng câu lệnh kỹ thuật chuẩn CTCO
│   ├── 03_ANTIGRAVITY_2.0_MASTERY_GUIDE.md    # Hướng dẫn khai thác môi trường lập trình tự hành
│   ├── 04_DEBUGGING_WITH_AI.md              # Phương pháp luận chẩn đoán lỗi 4 tầng (Vật lý - Logic)
│   ├── 05_EXAM_DEFENSE_PREPARATION.md       # Phương pháp mô phỏng phản biện và bảo vệ đồ án
│   └── TEMPLATES/                           # Hệ thống mẫu câu lệnh kỹ thuật chuẩn hóa
│       ├── MASTER_AGENT_INITIALIZE.md       # Prompt khởi tạo Agent đồng bộ ngữ cảnh
│       ├── HARDWARE_DEBUG_PROMPT.md         # Prompt chẩn đoán mạch điện và hiện tượng sụt áp
│       └── CODE_EXPLANATION_PROMPT.md       # Prompt phân tích bản chất giải thuật và mã nguồn
│
├── 📜 agent_rules/                          # BỘ QUY CHUẨN VẬN HÀNH CỦA HỆ THỐNG AGENT
│   ├── 01_CORE_OPERATING_PRINCIPLES.md      # Nguyên tắc sư phạm gợi mở (Socratic Method)
│   ├── 02_KNOWLEDGE_LOGGING_AND_GIT_SYNC.md   # Tiêu chuẩn số hóa tri thức và đồng bộ hóa Git
│   ├── 03_MULTI_AGENT_HANDOVER_PROTOCOL.md    # Giao thức bàn giao phiên nghiên cứu giữa các Agent
│   └── MASTER_AGENT_PROMPT.md               # Mẫu câu lệnh khởi tạo đồng bộ Agent
│
└── 🚗 projects/                             # KHÔNG GIAN DỰ ÁN THỰC NGHIỆM
    └── smart_parking/                       # Đề tài: Hệ thống Bãi đỗ xe thông minh (ESP32 & IR)
        ├── docs/                            # Đặc tả kỹ thuật, cẩm nang phân tích A-Z & kho kinh nghiệm
        │   ├── SMART_PARKING_A_TO_Z.md
        │   ├── EXPERIENCE_KNOWLEDGE_BASE.md
        │   └── Huong_Dan_Hieu_Ban_Chat_He_Thong_A_Z.pdf
        ├── firmware/                        # Mã nguồn nhúng (C++) và bảng sơ đồ chân tín hiệu
        │   ├── it.ino
        │   └── WIRING_PINOUT.md
        ├── assets/                          # Bản vẽ và hình ảnh sa bàn thực nghiệm
        │   └── prototype.jpg
        └── workspace/                       # Không gian quản trị tiến độ và nhật ký riêng của đề tài
            ├── PROJECT_CONTEXT.md
            ├── WORK_LOG.md
            └── AGENT_INSTRUCTIONS.md
```

---

## 🚀 Quy Trình Khởi Động Dành Cho Người Học (Mentee)

### 📌 Lưu ý quan trọng khi thiết lập thư mục trên máy tính:
* **Vị trí lưu trữ:** Khuyến nghị đặt tại `D:\projects\ai-agent-project-mentor` hoặc `C:\workspace\ai-agent-project-mentor`. **Tuyệt đối không lưu tại thư mục có dấu tiếng Việt hoặc khoảng trắng** (như Desktop có tên tài khoản tiếng Việt) để tránh lỗi trình biên dịch Arduino IDE và Git.
* **Kiểm tra cấu trúc giải nén:** Mở thư mục dự án phải thấy trực tiếp tệp `AGENTS.md` và `README.md` (tránh hiện tượng bị lồng 2 tầng thư mục con khi giải nén).

### Các bước bắt đầu phiên làm việc:
1. **Bước 1: Kích hoạt quyền đồng bộ Git (1-Click)**
   * Chạy tệp `kich_hoat_dong_bo_github.bat` trong thư mục để tự động xác thực quyền đẩy code lên GitHub.
2. **Bước 2: Mở Workspace trên Google Antigravity**
   * Khởi chạy Antigravity &rarr; Chọn `File` &rarr; `Open Folder` &rarr; Trỏ đến **đúng thư mục gốc** `ai-agent-project-mentor`.
   * Antigravity sẽ tự động kích hoạt tệp quy tắc nền tảng `AGENTS.md`.
3. **Bước 3: Đồng bộ Ngữ cảnh Phiên làm việc**
   * Sao chép nội dung từ `ai_agent_methodology/TEMPLATES/MASTER_AGENT_INITIALIZE.md` (hoặc `agent_rules/MASTER_AGENT_PROMPT.md`) và gửi vào giao diện trò chuyện với Agent để thiết lập ngữ cảnh cho phiên nghiên cứu.
4. **Bước 4: Ghi nhận Lịch sử và Đồng bộ Git**
   * Kết thúc mỗi phiên làm việc, Agent có trách nhiệm hỗ trợ cập nhật kết quả vào `projects/smart_parking/workspace/WORK_LOG.md` và hướng dẫn thực hiện đồng bộ hóa lên GitHub repository.

---

## 👥 Cơ Cấu Phân Nhiệm & Tham Gia Dự Án
* **Mentor phụ trách:** Cố vấn phương pháp luận nghiên cứu, định hướng kiến trúc kỹ thuật và giám sát thực nghiệm.
* **AI Agent Trợ lý:** Google Antigravity (Gemini) – Hỗ trợ phân tích kỹ thuật, truy vấn tài liệu và đề xuất phương án giải quyết sự cố 24/7.
* **Người học (Mentee):** Trực tiếp nghiên cứu, thực nghiệm trên phần cứng, phân tích mã nguồn và làm chủ toàn diện hệ thống.
