#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, *px;
	px=&x;
	scanf("%d", &x);
	getchar();
	printf("x = %d == *px = %d\n", x,*px);
	printf("px = %d == &x = %d\n", px, &x);
}
