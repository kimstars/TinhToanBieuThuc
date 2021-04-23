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


struct Stack {
	int top;
	int capacity;
	int* array;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(capacity * sizeof(int));
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

void push(struct Stack* stack, int item)
{
	stack->array[++stack->top] = item;
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return 0;
}
char top(struct Stack* stack){
	if (isEmpty(stack)){
		return;
	}
	return stack->array[stack->top];
}
int popInt(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return 0;
}

char* PostFix(char* s){   
    struct Stack * k = createStack(strlen(s));
	char *res = (char*)calloc(strlen(s)*2,sizeof(char));
    int i,j;
    for (i = 0, j = -1; s[i] ; ++i){
        if(LaSo(s[i])){
			while(LaSo(s[i])){
				res[++j] = s[i++];
			}
			res[++j] = 32;
        }
		if (s[i] == '(') {
			push(k, s[i]);
		}
		if (s[i] == ')'){
			while(top(k) != '('){
				res[++j] = pop(k);
				res[++j] = 32;
			}
			--k->top;
		}
		if (LaTT(s[i])){
			while(!isEmpty(k) && 
					uutien(s[i]) <= uutien(top(k))){
				res[++j] = 32;
				res[++j] = pop(k);
			}
			push(k,s[i]);
		}
    }
	while(!isEmpty(k)){
		res[++j] = 32;
		res[++j] = pop(k);
	}
	printf("post fix : %s\n", res);
	return res;
}


int CalculatorPostFix(char *s){
	struct Stack* k = createStack(strlen(s)); // luu so
	int x= 0, a = 0,b = 0,c = 0;
	int i;
	for (i = 0;s[i]; ++i){
		if(LaSo(s[i])){
			while(LaSo(s[i])){
				x = x*10 + s[i++] - '0';
			}
			push(k,x);
			x = 0;
		}
		if(!isEmpty(k) && LaTT(s[i])){
			a = popInt(k);
			b = popInt(k);
			if(s[i] == '-') c = b - a;
            if(s[i] == '+') c = b + a;
            if(s[i] == '*') c = b * a;
            if(s[i] == '/' && a != 0) c = b / a;
            if(s[i] == '^') c = pow(b,a);
			push(k,c);
		}
	}
	return popInt(k);
}


int main(){
	char s[1000] ;
	do{
		printf("Nhap bieu thuc :\n");
		gets(s);
        if(!checkBieuThuc(s)){
			printf("\nVui long nhap lai bieu thuc dung\n");
		}
    }while(!checkBieuThuc(s));
	char * res = PostFix(s);
	// char * res = "3 3 +";
	int res1 = CalculatorPostFix(res);
	// printf("\npost fix %s", res);
	printf("\nket qua la %d", res1);

	
}