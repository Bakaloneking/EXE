#include <stdio.h>

struct ponto{
	int x,y;
};

void atribui(struct ponto *p){
	(*p).x=10;
	(*p).y=20;
}

int main(){
	/*Por Referencia*/
	struct ponto p1;
	atribui(&p1);
	printf("x=%d\n", p1.x);
	printf("x=%d\n", p1.y);
	return 0;
}
