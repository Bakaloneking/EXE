#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=3, j=5, *p, *q;
	//p=&i;
	/**q=&j;*/
	//p=&*&i;
	/*i=(*&)j;*/
	//i=*&*&j;
	//q=&p;
	/*i=(*p)+++*q;*/
	printf("%d", i);
}
