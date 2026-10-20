# SMART PARKING SYSTEM: KHO DỰ ÁN & HỆ THỐNG MENTORING CÙNG AI AGENT

> **Kho lưu trữ nghiên cứu, học tập và hướng dẫn làm đồ án IoT bằng AI Agent (Google Antigravity 2.0).**  
> Dự án: **Hệ thống bãi đỗ xe thông minh ứng dụng cảm biến khoảng cách và vi điều khiển ESP32.**

---

## 🎯 Triết Lý: "Chỉ Cho Cần Câu Chứ Không Cho Con Cá"
Dự án này không nhằm mục đích làm hộ đồ án cho sinh viên, mà là một **môi trường huấn luyện tư duy kỹ thuật và phương pháp làm việc cùng AI Agent**. Sinh viên sẽ trực tiếp làm chủ hệ thống, rèn luyện kỹ năng phân tích giải thuật, chẩn đoán phần cứng và tự tin bảo vệ đồ án trước hội đồng.

---

## 📂 Cấu Trúc Kho Lưu Trữ

```
ai-agent-project-mentor/
├── README.md                          # Tài liệu tổng quan & hướng dẫn bắt đầu
│
├── docs/                              # Kho tri thức định hướng tư duy & bản chất
│   ├── 01_AI_MINDSET_GUIDE.md         # Tư duy & Phương pháp làm việc hiệu quả với AI
│   ├── 02_ANTIGRAVITY_AGENT_GUIDE.md  # Hướng dẫn sử dụng Google Antigravity 2.0
│   ├── 03_SMART_PARKING_A_TO_Z.md     # Bản chất kỹ thuật hệ thống bãi xe (5 tầng tư duy)
│   └── Huong_Dan_Hieu_Ban_Chat_He_Thong_A_Z.pdf # Bản PDF in ấn đẹp, trực quan
│
├── firmware/                          # Mã nguồn nhúng & Sơ đồ phần cứng
│   ├── it.ino                         # Code C++ nạp trên ESP32 (Web Server + FSM)
│   └── WIRING_PINOUT.md               # Bảng tra cứu chân GPIO & an toàn nguồn
│
├── agent_workspace/                   # Không gian tương tác cho AI Agent trên Antigravity
│   ├── AGENT_INSTRUCTIONS.md          # Bộ quy tắc bắt buộc cho Agent (Socratic Mentor)
│   ├── PROJECT_CONTEXT.md             # Bối cảnh hiện trạng, bug tracking & roadmap
│   └── WORK_LOG.md                    # Nhật ký tiến độ nghiên cứu & làm việc liên tục
│
└── assets/                            # Hình ảnh sa bàn thực nghiệm & tài liệu mô hình
    └── prototype.jpg                  # Ảnh thực tế mô hình bãi đỗ xe
```

---

## 🚀 Hướng Dẫn Dành Cho Mentee: Bắt Đầu Trong 3 Bước

1. **Bước 1: Cài đặt và mở dự án trên Google Antigravity**
   * Mở Antigravity trên laptop &rarr; `File` &rarr; `Open Folder` &rarr; Chọn thư mục dự án này.
2. **Bước 2: Kích hoạt Agent trợ lý**
   * Trong khung chat của Antigravity, gõ:
     > *"Chào Agent! Mình là Mai Uyên. Mình vừa mở dự án Smart Parking. Bạn hãy đọc file `agent_workspace/AGENT_INSTRUCTIONS.md` và `agent_workspace/PROJECT_CONTEXT.md` để nắm bối cảnh, sau đó hướng dẫn mình tiếp tục nhé!"*
3. **Bước 3: Tự động ghi chép nhật ký & Đồng bộ Git**
   * Sau mỗi buổi làm việc cùng Mentor hoặc tự học với Agent, Agent sẽ tự động ghi chép vào `agent_workspace/WORK_LOG.md` và hướng dẫn bạn đẩy code lên GitHub.

---

## 👥 Ban Cố Vấn & Hướng Dẫn
* **Mentor / Giảng viên:** Cố vấn trực tiếp phương pháp tư duy và dẫn dắt thực hành.
* **AI Agent:** Google Antigravity (Gemini) – Trợ lý kỹ thuật 24/7.
* **Mentee:** Nguyễn Trần Mai Uyên – Sinh viên thực hiện.
