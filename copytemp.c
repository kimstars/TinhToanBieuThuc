#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char data;
    struct tree * left;
    struct tree * right;
}* node;

node stack[30]; // stack lưu node 

int top = -1;

node newNode(char b) {
    node temp = (node)malloc(sizeof(node));
    temp -> data = b;
    temp -> left = temp -> right = NULL;
    return temp;
}
void push(node temp) {
    stack[++top] = temp;
}
node pop() {
    node p;
    p = stack[top--];
    return (p);
}

void inorder(node t) {
    if (t != NULL) {
        inorder(t -> left);
        printf("%c", t -> data);
        inorder(t -> right);
    }
}
void preorder(node t) {
    if (t != NULL) {
        printf("%c", t ->data);
        preorder(t ->left);
        inorder(t ->right);
    }
}
void postorder(node t) {
    if (t != NULL) {
        postorder(t -> left);
        postorder(t -> right);
        printf("%c", t -> data);
    }
}

int isOperator(char c){
    if( c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '^') return 1;
    return 0;
}

void main() {
    char postfix[20];
    node temp, t;
    int i;
    printf("Enter the postfix expression\n");
    gets(postfix);
    for (i = 0; postfix[i] != NULL; i++){
        if (isOperator(postfix[i])) { // gặp toán tử 
                temp = newNode(postfix[i]); //node là toán tử, leaf là toán hạng
                // lấy hai phần tử đỉnh stack cho vào hai nhánh cây nhị phân
                temp -> right = pop();
                temp -> left = pop();
                // đẩy node trở lại stack
                push(temp);
            } else {
                temp = newNode(postfix[i]);
                push(temp);
            }
    }
    t = pop();
    inorder(t);
    printf("\n");
    preorder(t);
    printf("\n");
    postorder(t);
    return 0;
}