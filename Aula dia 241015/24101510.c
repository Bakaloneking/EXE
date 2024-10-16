#include <stdio.h>

int main(){
	int *p = 0x5DC; //1500
	p++;
	printf("p=%d\n", p);
	p=p+15;
	printf("p=%d\n", p);
	p=p-2;
	printf("p=%d\n", p);
	return 0;
}
