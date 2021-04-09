#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;
 
template <class KieuDuLieuTongQuat>
class Stack
{
private:
	struct Node
	{
		KieuDuLieuTongQuat Value;
		Node *pNext;
	};
	Node *pHead;
	void Huy()
	{
		Node *p = pHead;
		while (pHead)
		{
			p = pHead;
			pHead = p->pNext;
			delete p;
		}
	}
	Node *CreateNode(KieuDuLieuTongQuat x)
	{
		Node * p = new Node;
		if (!p) exit(1);
		p->Value = x;
		p->pNext = NULL;
		return p;
	}
public:
	Stack();
	~Stack()
	{
		Huy();
	}
	bool Empty()
	{
		return (pHead == NULL);
	}
	int Size()
	{
		Node *p = pHead;
		KieuDuLieuTongQuat i = 0;
		while (p)
		{
			p = p->pNext;
			i++;
		}
		return i;
	}
	KieuDuLieuTongQuat Top()
	{
		if (pHead)
			return pHead->Value;
		return -1;
	}
	void Push(KieuDuLieuTongQuat x)
	{
		Node * p = CreateNode(x);
		if (!pHead)
			pHead = p;
		else
		{
			p->pNext = pHead;
			pHead = p;
		}
	}
	void Pop()
	{
		if (pHead)
		{
			Node *p = pHead;
			pHead = p->pNext;
			delete p;
		}
	}
};
 
template <class KieuDuLieuTongQuat>
Stack<KieuDuLieuTongQuat>::Stack()
{
	pHead = NULL;
}
 
bool LaSo(char c)
{
	return (c >= '0' && c <= '9');
}
bool LaTT(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int UT(char c)
{
 
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/' || c == '%') return 2;
	if (c == '^') return 3;
	return 0;
}
 
 
string ChuyenTrungToSangHauTo(string TT)
{
	string HT = "";
	Stack<char> S;
	int len = TT.size();
	for (int i = 0; i < len; i++)
	{
		if (LaSo(TT[i]))
		{
			while (LaSo(TT[i]))
				HT += TT[i++];
			HT += ' ';
		}
		if (TT[i] == '(')
			S.Push(TT[i]);
		if (TT[i] == ')')
		{
			while (S.Top() != '(')
			{
				HT += S.Top();
				S.Pop();
			}
			S.Pop();
		}
		if (LaTT(TT[i]))
		{
			while (!S.Empty() && UT(S.Top()) >= UT(TT[i]))
			{
				HT += S.Top();
				S.Pop();
			}
			S.Push(TT[i]);
		}
	}
	while (!S.Empty())
	{
		HT += S.Top();
		S.Pop();
	}
	return HT;
}
float TinhHauTo(string HT)
{
	Stack<float> S;// lưu bọn toán hạng nhé bạn chẻ ơi (số í)
	float x = 0, a, b, c;
	int len = HT.size();
	for (int i = 0; i < len; i++)
	{
		if (LaSo(HT[i])) // nếu em nó là số ? 
		{
			while (LaSo(HT[i]))
				x = x * 10 + HT[i++] - 48; // nếu em nó có hai chữ số trở lên thì viết lại cấu tạo số 
			S.Push(x);// rồi ném em nó vào stack nhé bạn chẻ ~~ 
			x = 0;
		}
		if (LaTT(HT[i]))
		{
			a = S.Top();// lấy cái đầu ra cmnl -> a
			S.Pop();// vứt cmn cái đầu tiên đi
			b = S.Top();// lấy cái tiếp theo -> b
			S.Pop(); // :) lại vứt cmn em nó đi luôn. như thay áo vậy :3
			if (HT[i] == '-') c = b - a;
			if (HT[i] == '*') c = b * a;
			if (HT[i] == '/') c = b / a;
			if (HT[i] == '+') c = b + a;
			if (HT[i] == '%') c = int(b) % int(a);
			if (HT[i] == '^') c = pow(b , a);
			S.Push(c);
		}
	}
	return S.Top();
}
int main()
{
	string a = ChuyenTrungToSangHauTo("11+111*100");
	cout << TinhHauTo(a);
}