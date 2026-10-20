# SMART PARKING SYSTEM: KHO DỰ ÁN & HỆ THỐNG MENTORING CÙNG AI AGENT

> **Kho lưu trữ nghiên cứu, học tập và hướng dẫn làm đồ án IoT bằng AI Agent (Google Antigravity 2.0).**  
> Dự án: **Hệ thống bãi đỗ xe thông minh ứng dụng cảm biến khoảng cách và vi điều khiển ESP32.**

---

## 🎯 Triết Lý: "Chỉ Cho Cần Câu Chứ Không Cho Con Cá"
Dự án này không nhằm mục đích làm hộ đồ án cho sinh viên, mà là một **môi trường huấn luyện tư duy kỹ thuật và phương pháp làm việc cùng AI Agent**. Sinh viên sẽ trực tiếp làm chủ hệ thống, rèn luyện kỹ năng phân tích giải thuật, chẩn đoán phần cứng và tự tin bảo vệ đồ án trước hội đồng.

---

## 📂 Cấu Trúc Kho Lưu Trữ Chuẩn Hóa

```
ai-agent-project-mentor/
├── README.md                                # Tài liệu tổng quan & hướng dẫn bắt đầu
│
├── agent_rules/                             # BỘ NGUYÊN TẮC HOẠT ĐỘNG DÀNH CHO CÁC AGENT
│   ├── 01_CORE_OPERATING_PRINCIPLES.md      # Triết lý "Cho cần câu", phương pháp Socratic gợi mở
│   ├── 02_KNOWLEDGE_LOGGING_AND_GIT_SYNC.md # Quy định ghi chép nhật ký & tự động đồng bộ GitHub
│   ├── 03_MULTI_AGENT_HANDOVER_PROTOCOL.md  # Giao thức bàn giao và tiếp nối giữa các Agent
│   └── MASTER_AGENT_PROMPT.md               # Mẫu Prompt khởi tạo Agent dùng cho mọi phiên chat mới
│
├── docs/                                    # KHO TRI THỨC NỀN TẢNG & KINH NGHIỆM THỰC CHIẾN
│   ├── 01_AI_MINDSET_GUIDE.md               # Tư duy & Phương pháp làm việc hiệu quả với AI
│   ├── 02_ANTIGRAVITY_AGENT_GUIDE.md        # Hướng dẫn sử dụng Google Antigravity 2.0
│   ├── 03_SMART_PARKING_A_TO_Z.md           # Bản chất kỹ thuật hệ thống bãi xe (5 tầng tư duy)
│   ├── EXPERIENCE_KNOWLEDGE_BASE.md         # Kho kinh nghiệm xử lý lỗi thực chiến (5 lỗi kinh điển)
│   └── Huong_Dan_Hieu_Ban_Chat_He_Thong_A_Z.pdf # Bản PDF in ấn đẹp, trực quan
│
├── firmware/                                # MÃ NGUỒN VÀ ĐẤU NỐI PHẦN CỨNG
│   ├── it.ino                               # Code C++ nạp trên ESP32 (Web Server + FSM)
│   └── WIRING_PINOUT.md                     # Bảng tra cứu chân GPIO & an toàn nguồn
│
├── agent_workspace/                         # KHÔNG GIAN TƯƠNG TÁC CHO AGENT TRÊN MÁY MENTEE
│   ├── AGENT_INSTRUCTIONS.md                # Bộ quy tắc bắt buộc cho Agent khi chạy trên máy
│   ├── PROJECT_CONTEXT.md                   # Bối cảnh hiện trạng, bug tracking & roadmap
│   └── WORK_LOG.md                          # Nhật ký tiến độ nghiên cứu & làm việc liên tục
│
└── assets/                                  # HÌNH ẢNH SA BÀN THỰC ĐỊA
    └── prototype.jpg                        # Ảnh thực tế mô hình bãi đỗ xe
```

---

## 🚀 Hướng Dẫn Khởi Tạo Nhanh Cho Mentee (Trong 3 Bước)

1. **Bước 1: Mở thư mục dự án trên Google Antigravity**
   * Mở Antigravity trên laptop &rarr; `File` &rarr; `Open Folder` &rarr; Chọn thư mục `ai-agent-project-mentor`.
2. **Bước 2: Kích hoạt Agent bằng Mẫu Prompt Chuẩn**
   * Mở file `agent_rules/MASTER_AGENT_PROMPT.md`, copy toàn bộ nội dung và dán vào khung chat của Antigravity.
   * Agent sẽ tự động đọc các nguyên tắc, đồng bộ lịch sử và hướng dẫn bạn bước tiếp theo.
3. **Bước 3: Tự động ghi chép nhật ký & Đồng bộ Git**
   * Sau mỗi buổi làm việc cùng Mentor hoặc tự học với Agent, Agent sẽ tự động ghi chép vào `agent_workspace/WORK_LOG.md` và hướng dẫn bạn đẩy code lên GitHub repo.

---

## 👥 Ban Cố Vấn & Hướng Dẫn
* **Mentor / Giảng viên:** Cố vấn trực tiếp phương pháp tư duy và dẫn dắt thực hành.
* **AI Agent:** Google Antigravity (Gemini) – Trợ lý kỹ thuật 24/7.
* **Mentee:** Nguyễn Trần Mai Uyên – Sinh viên thực hiện.
