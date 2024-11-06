#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=3, j=5, *p=&i, *q=&j;
	printf("%d\n",p==&i);
	printf("%d\n", *p-*q);
	printf("%d\n", **&p);
}
