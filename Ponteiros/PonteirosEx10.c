#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=5, *px=&x;
	printf("%u %d %d %d %d\n", px, *px+2, **&px, 3**px, **&px+4);
}
