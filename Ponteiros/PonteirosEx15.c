#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=10, *px=&x, **ppx=&px;
	float y=5.9, *py=&y, **ppy=&py;
	printf("a)x=%d\n", x);
	printf("b)*py=%f\n", *py);
	printf("c)px=%d\n", px);
	printf("d)&y=%d\n",&y);
	printf("e)*px=%d\n",*px);
	printf("f)y=%f\n", y);
	printf("g)*ppx=%d\n",*ppx);
	printf("h)py=%d\n", py);
	printf("i)&x=%d\n", &x);
	printf("j)py++=%d\n",py++);
	printf("k)*px--=%d\n",*px--);
	printf("l)**ppy=%d\n",**ppy);
	printf("m)&ppy=%d\n",&ppy);
	printf("n)*&px=%d\n",*&px);
	printf("o)**ppx++=%d\n",**ppx++);
	printf("p)px++=%d\n",px++);
	printf("q)&ppx=%d\n",&ppx);
}
