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
struct StackFloat{
    int top;
    int capacity;
    float * array;
};

struct StackFloat* createStackFloat(int capacity){
    struct StackFloat* stack = (struct StackFloat*)malloc(sizeof(struct StackFloat));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (float*)malloc(stack->capacity * sizeof(float));
    return stack;
};

int fisFull(struct StackFloat* stack)
{
	return stack->top == stack->capacity - 1;
}

int fisEmpty(struct StackFloat* stack)
{
	return stack->top == -1;
}

void fpush(struct StackFloat* stack, float item){
    if(!fisFull(stack)) {
		stack->array[++stack->top] = item;

	}

}

float fpop(struct StackFloat* stack){
    if (!fisEmpty(stack)){
		return stack->array[stack->top--];
	}
}

float ftop(struct StackFloat* stack){
	if (!fisEmpty(stack)){ 
		return stack->array[stack->top];
	}
}


//END STACK FLOAT


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
void append(char* s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

//END CHAR STACK


char* PostFix(char *s){
    int len = strlen(s);
    char *res = (char*)calloc(len,sizeof(char));
    struct Stack* k = createStack(len);
    int i;
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

float CalculatorPostFix(char s[]){
	int len = strlen(s);
	struct StackFloat * k = createStackFloat(len);
	float x = 0, a = 0,b = 0,c = 0;
	int i;
	for (i = 0;i < len; i++){
		if(LaSo(s[i])){
			while(LaSo(s[i])){
				x = x*10 + s[i++] - '0';
			}
			fpush(k,x);
			x = 0;
		}
		if(LaTT(s[i])){
			a = fpop(k);
			b = fpop(k);
			if(s[i] == '-') c = b - a;
            if(s[i] == '+') c = b + a;
            if(s[i] == '*') c = b * a;
            if(s[i] == '/' && a != 0) c = b / a;
//            if(s[i] == '%' && a != 0) c = (b) % (a);
            if(s[i] == '^') c = pow(b,a);
			fpush(k,c);
		}
	}
	return fpop(k);
}


int main(){
	char s[1000];
	do{
		printf("Nhap bieu thuc :\n");
		gets(s);
        if(!checkBieuThuc(s)){
			printf("\nVui long nhap lai bieu thuc dung\n");
		}
    }while(!checkBieuThuc(s));
	char * res = PostFix(s);
	float res1 = CalculatorPostFix(res);
	// printf("\npost fix %s", res);
	printf("\nket qua la %.1f", res1);

}