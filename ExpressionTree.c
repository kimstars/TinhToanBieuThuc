#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    char data;
    struct node *left;
    struct node *right;
}*Node;

//------------------------------------------------STACK BEGINNING
typedef struct stack{
    int top;
    int capacity;
    Node *array;
}Stack;

Stack* createStack(int capacity){
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Node*)malloc(stack->capacity * sizeof(Node));
    return stack;
};

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, Node *item){
    if(isFull(stack)) return;
    stack->array[++stack->top] = item;
//    printf("%c pushed into stack\n", item);
}

Node pop(Stack* stack){
    if (isEmpty(stack)) return;
    return stack->array[stack->top--];
}

Node top(Stack* stack){
    if (isEmpty(stack)) return;
    return stack->array[stack->top];
}
//--------------------------------------------------NODE CREATION



int isOperator(char c){
    if( c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '^') return 1;
    return 0;
}


Node *newNode(char v){
    Node temp = (Node)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = v;
    return temp;
}

Node *constructTree(char *postfix){
    Stack * k = createStack(100);
    Node t, t1 ,t2;
    int i;
    for(i = 0 ; i < strlen(postfix); i++){
        if (!isOperator(postfix[i])){
            t = newNode(postfix[i]);
            push(k,t);
        }else{
            t = newNode(postfix[i]);

            t1 = pop(k);
            t2 = pop(k);

            t->right = t1;
            t->left = t2;

            push(k,t);
        }
    }
    t = pop(k);
    return t;
}



void print(Node t){
    if(t != NULL){
        print(t->left);
        printf("%c",t->data);
        print(t->right);
    }
}

void inorder(Node t) {
    if (t != NULL) {
        inorder(t -> left);
        printf("%c", t -> data);
        inorder(t -> right);
    }
}
void preorder(Node t) {
    if (t != NULL) {
        printf("%c", t -> data);
        preorder(t -> left);
        inorder(t -> right);
    }
}
void postorder(Node t) {
    if (t != NULL) {
        postorder(t -> left);
        postorder(t -> right);
        printf("%c", t -> data);
    }
}


int main(){
    char postfix[] = "ab+ef*g*-";
    Node x = constructTree(postfix);
    print(x);

    printf("\n");

    preorder(x);
}