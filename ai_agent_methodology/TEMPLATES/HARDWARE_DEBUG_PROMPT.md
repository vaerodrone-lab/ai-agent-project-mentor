# MẪU PROMPT CHẨN ĐOÁN LỖI PHẦN CỨNG (HARDWARE DEBUG PROMPT)

```markdown
Chào Agent, mạch phần cứng của tôi đang gặp sự cố. Bạn hãy giúp tôi chẩn đoán theo phương pháp 4 bước khoa học (Nguồn -> Dây nối -> Mức tín hiệu -> Code).

1. Thông tin phần cứng:
- Vi điều khiển: [Ví dụ: ESP32 DevKit 30 chân]
- Module/Linh kiện bị lỗi: [Ví dụ: Cảm biến FC-51 / Động cơ Servo MG90S / Màn hình LCD 1602 I2C]
- Các chân GPIO đang cắm: [Ví dụ: GPIO 32, 33...]
- Nguồn cấp đang dùng: [Ví dụ: Nguồn cắm cổng USB 5V / Nguồn ngoài DC 5V 2A]

2. Triệu chứng thực tế quan sát được bằng mắt thường:
- Đèn nguồn (Power LED) trên mạch: [Ví dụ: Sáng bình thường / Sáng lờ mờ / Không sáng]
- Đèn tín hiệu (Detect/Signal LED): [Ví dụ: Luôn sáng đỏ dù không có vật cản / Không bao giờ sáng]
- Hiện tượng bất thường khác: [Ví dụ: ESP32 bị reset liên tục khi servo quay / Màn hình LCD chỉ hiện ô đen]

Nhiệm vụ của bạn:
- Hãy liệt kê cho tôi 3 nguyên nhân bản chất khả dĩ nhất.
- Hướng dẫn tôi kiểm tra lần lượt từng nguyên nhân một bằng các thao tác thực nghiệm trên mạch.
- Khoan sửa code vội, hãy tập trung vào phần cứng và mức điện áp trước.
```
