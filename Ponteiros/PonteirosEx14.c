#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, *pi, **ppi;
	float f, *pf, **ppf;
	i=f;
	/*pf=&i;*/
	*pf=5.9;
	/**ppi=&pi;*/
	*pf=10;
	f=i;
	/*pi=&f;*/
	*pi=7.3;
	ppf=&pf;
	**ppi=100;
}
