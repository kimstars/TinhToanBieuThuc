#include <stdio.h>
#include <stdlib.h>
int main(){
    char *s = (char*)calloc(100,sizeof(char));
    gets(s);
    s[strlen(s)] = 65;
    char a = ' ';
    printf("%d", a);
}