#include <stdio.h>

int main(){
	void *pp;
	int *p1, x=10;
	p1=&x;
	pp=&x;
	printf("End. de pp = %p\n",pp);
	pp=&p1;
	printf("End. de pp = %p\n",pp);
	pp=p1;
	printf("End. de pp = %p\n",pp);
	return 0;
}
