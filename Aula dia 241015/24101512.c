#include <stdio.h>

int main(){
	int *p1, *p2, x, y;
	p1=&x;
	p2=&y;
	if(p1>p2){
		printf("p1>p2\n");
	}else printf("p1<=p2\n");
	return 0;
}
