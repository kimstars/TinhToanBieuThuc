#include <stdio.h>

float toFloat(char *a){
	int len = strlen(a);
	int i ;
	float res = 0;
	for(i = 0; i < len; i++){
		res = res*10 + a[i] -'0';
	}
	return res;
}

int main(){
    char *a = "45332";
    float res = toFloat(a);
    printf("%f",res);
}