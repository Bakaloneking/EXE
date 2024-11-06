#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=10, *px=&x;
	printf("x = %d == px = %d\n", &x,px);
	printf("x = %d == *px = %d\n", x, *px);
	*px=20;
	printf("x = %d\n", x);
	x=15;
	printf("*px = %d\n", *px);
	printf("px=%d\n", px);
}
