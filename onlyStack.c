#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool LaSo(char c){
    return (c >= '0' && c <= '9');
}

bool LaTT(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int uutien(char c){
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/' || c == '%') return 2;
	if (c == '^') return 3;
	return 0;
}

bool checkBieuThuc(char* s){
    int length = strlen(s);
    int res = 0;
	int i;
    for(i = 0 ; i < length; i++){
        if(s[i] == ')') res--;
        if(s[i] == '(') res++;
    }
    if(res){
        return 0;
    }else{
        return 1;
    }
}
// FLOAT STACK DEFINITE

//CHAR STACK BEGIN

struct Stack {
	int top;
	unsigned capacity;
	char* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*)malloc(stack->capacity * sizeof(char));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, char item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;

}

char pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return;
	return stack->array[stack->top--];
}
char top(struct Stack* stack){
	if (isEmpty(stack)){
		return;
	}
	return stack->array[stack->top];
}
void append(char* s, char c) { // ----------------------------------------------------
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

//END CHAR STACK


char* PostFix(char *s){
    int len = strlen(s);
    char *res = (char*)calloc(len,sizeof(char));
    struct Stack* k = createStack(len);
    int i = 0;
    for (i = 0; i < len; i++){
        if(LaSo(s[i])){
            while(LaSo(s[i])){
                append(res,s[i]);
                ++i;
            }
			append(res,' ');
        }
		if (s[i] == '(') push(k, s[i]);
		if (s[i] == ')'){
			while(top(k) != '('){
				append(res, pop(k));
			}
			k->top--;
		}
		if (LaTT(s[i])){
			while(!isEmpty(k) && uutien(s[i]) <= uutien(top(k))){
				append(res,pop(k));
			}
			push(k,s[i]);
		}
    }
	while(!isEmpty(k)){
		append(res,' ');
		append(res, pop(k));

	}
	printf("post fix : %s\n", res);
	return res;
}
void cat(char a[], char a1[]){
	int i, j, n1, n2;
	n1 = strlen(a);
	n2 = strlen(a1);
	j = 0;
	for(i = n1 ; i < n1+n2; i++){
		a[i] = a1[j++];
	}
	a[i] = '\0';
}

char* toString(int a){
	char str[20];    //create an empty string to store number
	sprintf(str, "%d", a); 
	return str;
}

float CalculatorPostFix(char s[]){
	int len = strlen(s);
	struct Stack * k = createStack(len); // luu so
	float x = 0, a = 0,b = 0,c = 0;
	int i;
	for (i = 0;i < len; i++){
		if(LaSo(s[i])){
			while(LaSo(s[i])){
				x = x*10 + s[i++] - '0';
			}
			push(k,x);
			x = 0;
		}
		if(LaTT(s[i])){
			a = pop(k);
			b = pop(k);
			if(s[i] == '-') c = b - a;
            if(s[i] == '+') c = b + a;
            if(s[i] == '*') c = b * a;
            if(s[i] == '/' && a != 0) c = b / a;
//            if(s[i] == '%' && a != 0) c = (b) % (a);
            if(s[i] == '^') c = pow(b,a);
			push(k,c);
		}
	}
	return pop(k);
}

void itos(int value, char* str) {
    sprintf(str, "%d", value);
}
int main(){
	// char s[1000];
	// do{
	// 	printf("Nhap bieu thuc :\n");
	// 	gets(s);
    //     if(!checkBieuThuc(s)){
	// 		printf("\nVui long nhap lai bieu thuc dung\n");
	// 	}
    // }while(!checkBieuThuc(s));
	// char * res = PostFix(s);
	// float res1 = CalculatorPostFix(res);
	// // printf("\npost fix %s", res);
	// printf("\nket qua la %.1f", res1);

	int a = 10;
	char str[10];
	itos(a,str);
	printf("%s", str);
}