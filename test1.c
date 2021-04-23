#include <stdio.h>



struct Stack {
	int top;
	unsigned capacity;
	char** array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char**)malloc(stack->capacity * sizeof(char*));
	int i;
	for(i = 0; i < capacity; i++){
		stack->array[i] =(char*)malloc(30*sizeof(char));
	}
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

void push(struct Stack* stack, char *item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;

}

char *pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return;
	return stack->array[stack->top--];
}
char *top(struct Stack* stack){
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

// test push mot ki tu

int main(){
    char *res = (char*)calloc(10,sizeof(char));
    struct Stack* k= createStack(100);

    append(res,'1');
    push(k,res);
    printf("top %s", top(k));
}