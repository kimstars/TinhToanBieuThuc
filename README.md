# Tính toán biểu thức
Bạn muốn thực hiện một loạt các phép tính ? bạn đang tìm kiếm giải pháp cho ý tưởng trên ? Thì nó ở đây này == 

Thuật toán là : Chuyển sang biểu thức hậu tố. Rồi bạn chẻ chỉ cần viết thêm cái hàm Tính toán Biểu thức Hậu tố là xong rồi bạn chẻ ơi ~~

# Thuật toán chuyển từ trung tố sang hậu tố
Khởi tạo Stack rỗng.
Khởi tạo 2 chuỗi x và token; i, j lần lượt là index của Infix và Postfix.
Duyệt vòng lặp for từ i = 1 cho đến cuối chuỗi Infix:
Nếu Infix[i] là toán hạng thì đưa vào Postfix.
Nếu Infix[i] là toán tử thì Push vào ngăn xếp S.
Nếu Infix[i] là “)” thì Pop vào ngăn xếp S (lấy giá trị trên đỉnh của S) sau đó đưa vào Postfix.
Output: Postfix là biểu thức hậu tố.

# Tính giá trị biểu thức hậu tố
Duyệt biểu thức dạng chuỗi từ trái sang phải:

Dùng hàm isdigit để kiểm tra:

Nếu là toán hạng thì dùng Push() đưa vào ngăn xếp S.
Nếu là toán tử thì Pop() 2 toán hạng trong ngăn xếp S ra, sau đó tính toán giá trị của chúng dựa vào toán tử này, sau đó Push() lại vào S.
Thực hiện cho đến khi gặp kí tự \0 kết thúc chuỗi.
Kết quả của biểu thức chính là phần tử còn lại cuối cùng trong ngăn xếp S.

