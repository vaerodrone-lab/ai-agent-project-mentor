# QUY CHUẨN LƯU TRỮ TRI THỨC & ĐỒNG BỘ GITHUB (KNOWLEDGE MANAGEMENT & GIT SYNC)
> *Mục tiêu: Toàn bộ quá trình nghiên cứu, chẩn đoán sự cố kỹ thuật và bài học thực nghiệm đều được số hóa, lưu trữ có cấu trúc trên GitHub repository nhằm phục vụ công tác theo dõi của Mentor và chuyển giao ngữ cảnh cho các Agent tiếp theo.*

---

## 1. NGUYÊN TẮC QUẢN TRỊ TIẾN ĐỘ & TRUY XUẤT LỊCH SỬ (TRACEABILITY)
Mọi phiên làm việc kỹ thuật đều phải được ghi nhận kết quả cụ thể. Khi hoàn thành một tính năng hoặc xử lý xong một sự cố kỹ thuật, Agent có trách nhiệm:

### A. Cập Nhật Nhật Ký Nghiên Cứu (`projects/<ten_project>/workspace/WORK_LOG.md`)
Ghi nhận theo cấu trúc chuẩn:
```markdown
### [YYYY-MM-DD HH:MM] - [Tiêu đề phiên làm việc / Tính năng / Sự cố xử lý]
* **Mục tiêu phiên làm việc:** (Ví dụ: Chẩn đoán nguyên nhân cảm biến báo chiếm chỗ khi bãi trống)
* **Các bước kỹ thuật đã triển khai:** (Quy trình kiểm tra phần cứng hoặc hiệu chỉnh mã nguồn)
* **Bản chất kỹ thuật người học đã làm chủ:** (Nguyên lý vật lý, điện áp hoặc giải thuật vừa được làm rõ)
* **Kết quả thực nghiệm trên mô hình:** (Trạng thái vận hành thực tế của hệ thống)
* **Nhiệm vụ tồn đọng & Định hướng phiên tiếp theo:** (Các nội dung kỹ thuật cần giải quyết tiếp theo)
```

### B. Trích Xuất Kinh Nghiệm Kỹ Thuật Vào Kho Dữ Kiện (`projects/<ten_project>/docs/EXPERIENCE_KNOWLEDGE_BASE.md`)
Khi giải quyết thành công một sự cố phần cứng hoặc phần mềm điển hình:
* Agent tổng hợp thành một **Thẻ phân tích kinh nghiệm kỹ thuật (Technical Experience Card)** lưu vào `projects/<ten_project>/docs/EXPERIENCE_KNOWLEDGE_BASE.md`.
* Thẻ kinh nghiệm gồm: *Hiện tượng &rarr; Bản chất kỹ thuật & Nguyên nhân gốc rễ &rarr; Phương án khắc phục chuẩn hóa &rarr; Khuyến nghị phòng ngừa cho các dự án IoT tương tự*.

---

## 2. QUY TRÌNH ĐỒNG BỘ PHIÊN BẢN QUA GIT
Sau khi cập nhật mã nguồn hoặc văn bản kỹ thuật, Agent chủ động hướng dẫn người học thực hiện quy trình đồng bộ lên GitHub:

1. **Kiểm tra trạng thái thay đổi:**
   ```bash
   git status
   ```
2. **Thêm toàn bộ thay đổi vào khu vực chờ:**
   ```bash
   git add .
   ```
3. **Thực hiện Commit theo chuẩn mực kỹ thuật (Semantic Commit):**
   * `fix:` Khi hiệu chỉnh lỗi phần cứng hoặc giải thuật.
   * `docs:` Khi cập nhật tài liệu kỹ thuật, nhật ký tiến độ hoặc thẻ kinh nghiệm.
   * `feat:` Khi phát triển tính năng mới hoặc tích hợp mô-đun mới.
   * *Ví dụ:*
     ```bash
     git commit -m "docs: cap nhat nhat ky nghien cuu va the kinh nghiem cam bien FC-51"
     ```
4. **Đồng bộ hóa lên GitHub repository:**
   ```bash
   git push origin main
   ```

---

## 3. Ý NGHĨA DÀI HẠN ĐỐI VỚI HỆ THỐNG ĐA AGENT
* Dữ liệu trên GitHub đóng vai trò là **ngữ cảnh nạp sẵn (Context Injection)** cho các AI Agent tham gia trong các giai đoạn phát triển tiếp theo.
* Khi mở rộng đề tài hoặc thực hiện đồ án tốt nghiệp, các Agent kế tiếp sẽ kế thừa toàn bộ lịch sử lỗi và giải pháp, từ đó nâng cao tính chính xác và hiệu quả hỗ trợ kỹ thuật.
