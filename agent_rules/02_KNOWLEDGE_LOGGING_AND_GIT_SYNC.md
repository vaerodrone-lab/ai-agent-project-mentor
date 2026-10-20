# QUY TẮC LƯU TRỮ TRI THỨC & ĐỒNG BỘ GITHUB (KNOWLEDGE LOGGING & GIT SYNC)
> *Mục tiêu: Mọi quá trình nghiên cứu, sửa lỗi và kinh nghiệm thực chiến đều phải được số hóa, lưu trữ vĩnh viễn trên GitHub repo để làm kho tri thức cho các Agent và dự án sau này.*

---

## 1. NGUYÊN TẮC: MỌI PHIÊN LÀM VIỆC ĐỀU PHẢI ĐỂ LẠI DẤU VẾT
Không có phiên làm việc nào kết thúc trong im lặng. Mỗi khi kết thúc một buổi trao đổi hoặc hoàn thành một tính năng/sửa một lỗi, Agent có trách nhiệm:

### A. Cập Nhật Nhật Ký Tiến Độ (`agent_workspace/WORK_LOG.md`)
Bắt buộc ghi nhận theo định dạng chuẩn:
```markdown
### [YYYY-MM-DD HH:MM] - [Tên phiên làm việc / Tính năng / Lỗi xử lý]
* **Mục tiêu phiên:** (Ví dụ: Chẩn đoán lỗi bãi đỗ xe báo đỏ trên web)
* **Các bước đã thực hiện:** (Ghi rõ quá trình kiểm tra phần cứng hoặc sửa code)
* **Bản chất kỹ thuật mentee đã nắm được:** (Mentee đã hiểu thêm điều gì mới?)
* **Kết quả thực nghiệm trên mạch:** (Đã chạy ổn định chưa? Còn hiện tượng gì?)
* **Tồn đọng & Kế hoạch phiên tới:** (Những việc cần làm tiếp theo)
```

### B. Trích Xuất Kinh Nghiệm Thực Chiến Vào Kho Tri Thức (`docs/EXPERIENCE_KNOWLEDGE_BASE.md`)
Khi giải quyết xong một lỗi điển hình (ví dụ: lỗi sụt áp nguồn Servo, lỗi cảm biến bắt sàn Fomex, lỗi I2C address, lỗi kết nối WiFi AP Isolation):
* Agent **bắt buộc phải ghi lại một thẻ kinh nghiệm (Experience Card)** vào file `docs/EXPERIENCE_KNOWLEDGE_BASE.md`.
* Thẻ kinh nghiệm gồm: *Hiện tượng &rarr; Nguyên nhân gốc rễ &rarr; Cách khắc phục chuẩn &rarr; Bài học rút ra cho các project IoT tương tự*.

---

## 2. QUY TRÌNH ĐỒNG BỘ GITHUB CHUẨN XÁC
Sau khi cập nhật code hoặc tài liệu, Agent chủ động hỗ trợ hoặc nhắc nhở mentee thực hiện commit và push lên GitHub repo:

1. **Kiểm tra trạng thái:**
   ```bash
   git status
   ```
2. **Thêm toàn bộ thay đổi:**
   ```bash
   git add .
   ```
3. **Commit với thông điệp chuẩn mực (Semantic Commit):**
   * `fix:` nếu là sửa lỗi (ví dụ: `fix: cap nhat nguoc logic cam bien FC-51`)
   * `docs:` nếu là viết tài liệu hoặc cập nhật nhật ký (ví dụ: `docs: cap nhat work log ngay 20-10`)
   * `feat:` nếu là thêm tính năng mới (ví dụ: `feat: tich hop ket noi MQTT Cloud`)
   * *Mẫu lệnh:*
     ```bash
     git commit -m "docs: cap nhat nhat ky nghien cuu va kinh nghiem sua loi cam bien"
     ```
4. **Đẩy lên GitHub:**
   ```bash
   git push origin main
   ```

---

## 3. Ý NGHĨA DÀI HẠN DÀNH CHO CÁC AGENT TƯƠNG LAI
* Kho dữ liệu trên GitHub không chỉ dành cho mentee xem lại, mà chính là **ngữ cảnh nạp sẵn (Context Injection)** cho các AI Agent thế hệ tiếp theo.
* Khi mentee làm đồ án tốt nghiệp hoặc dự án mới, một Agent mới chỉ cần đọc lướt qua kho tri thức này là biết ngay: *Mentee có điểm mạnh/yếu gì, phong cách làm việc ra sao, đã từng vượt qua các lỗi kỹ thuật nào*, từ đó hỗ trợ chính xác hơn gấp nhiều lần.
