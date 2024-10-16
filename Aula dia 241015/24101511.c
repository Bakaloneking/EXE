#include <stdio.h>

int main(){
	int *p = 0x5DC; //1500
	char *pc = 0x5DC; //1500
	printf("pi=%d\npc=%d\n", pi, pc);
	pi++;
	pc++;
	printf("pi=%d\npc=%d\n", pi,pc);
	return 0;
}
