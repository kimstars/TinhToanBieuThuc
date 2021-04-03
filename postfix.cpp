#include <iostream>
#include <stack>
#include <math.h>

using namespace std;


bool LaSo(char c)
{
	return (c >= '0' && c <= '9');
}
bool LaTT(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int uutien(char c)
{
 
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/' || c == '%') return 2;
	if (c == '^') return 3;
	return 0;
}


string PostFix(string s){
    string res = ""; // cái chỗ để lưu kết quả này
    stack<char> k; // stack lưu bọn kí tự + - * /
    int len = s.size();
    for(int i = 0 ; i < len; i++){ // duyệt từ đầu chí cuối
        if(LaSo(s[i])){ //nếu gặp một e toán hạng 
            while(LaSo(s[i])){ // khi mà lũ em nó có nhiều hơn 1 chữ số
                res += s[i++]; // thì bố m duyệt qua từng em 
                // vì nhét vào string nên bố m ko phải quan tâm cấu tạo số làm đ j==
            }
            res += ' ';// :> để cái e nó đứng cách nhau ra cho dễ yêu <3
        } 
        if (s[i] == '(') k.push(s[i]); // gặp một con mở ngoặc nhét nó vào stack luôn :>
        if(s[i] == ')'){ // nếu gặp con đóng bracket thì ....
            while(k.top() != '('){ // nhét lũ toán tử vào res cho đến khi gặp con mở ngoặc thì thôi
                res += k.top(); // các e cộng trừ nhân chia được lấy ra cho vào res
                k.pop();
            }
            k.pop();// đá con mở ngoặc ko thương tiếc :> vì a đây đ cần 
        }
        if (LaTT(s[i])){ // :< nhét các e toán tử vào stack chung với bracket
            while(!k.empty() && uutien(s[i]) <= uutien(k.top()) ){ // == ưu tiên các e toán tử khỏe hơn vào chơi trước nhé bạn chẻ
                res +=  k.top(); // điểm ưu tiên của các em toán tử cao sẽ đi ra relax cùng bọn a trước:))
                k.pop();// lấy hết các e điểm cao hơn ra mới nhét e điểm thấp vào
            }
            k.push(s[i]);// nhét con e điểm ưu tiên thấp
        }
    }
    while(!k.empty()){//== nhà còn đứa nào nữa thì bắt hết đi
        res +=  k.top();
        k.pop();
    }
    return res;
}

double CalculatorPostFix(string s){
    stack<double> k; // == stack tên tao cho chúng mày sợ :>
    int len = s.size();
    double x = 0, a, b, c;
    for(int i = 0; i < len ; i++){
        if(LaSo(s[i])){
            while (LaSo(s[i])){
                x = x*10 + s[i++] - '0';
            }
            k.push(x);
            x = 0;
        }
        // gặp toán tử cái thì lấy hai cái số gần nhất vừa ném vào stack ra tính luôn
        // tính xong rồi thì lại ném cái kết quả vào cho tao nhé... cứ thế cứ thế ....
        // == dm dễ thế thôi mà cứ để giải thích nhiều là sao hả bạn chẻ :>
        if(LaTT(s[i])){
            a = k.top();k.pop();
            b = k.top(); k.pop();
            if(s[i] == '-') c = b - a;
            if(s[i] == '+') c = b + a;
            if(s[i] == '*') c = b * a;
            if(s[i] == '/' && a != 0) c = b / a;
            if(s[i] == '%' && a != 0) c = int(b) % int(a);
            if(s[i] == '^') c = pow(b,a);
            k.push(c);
        }
    }
    return k.top(); // kết quả cuối cùng thì m vừa nhét vào nó ở ngay đầu í :3

}


int main(){
    string s;

    cout << "nhap bieu thuc bo may tinh cho  == : " << endl;
    cin >> s;
    string res = PostFix(s);
    cout << CalculatorPostFix(res);
    return 0;


}
