#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, *ptx, **pp;
	float a, *pta, **pf;
	x=100; //verdadeiro
	/**pta=&a;
	ptx=&a;*/
	*pf=&a;
	/*pp=&pta;*/
	**pf=7.9;
	*ptx=20;
	ptx=&x;
	/*pp=&x;*/
	pf=&pta;
}
