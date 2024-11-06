#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, *px;
	px=&x;
	scanf("%d", &x);
	getchar();
	printf("%d", *px/5);
}
