#include "funcoes.h"
int soma(int a, int b){
	return a+b;
}

int subtracao(int a, int b){
	return a-b;
}
int multiplicacao(int a, int b){
	return a*b;
}
float divisao(int a, int b){
	if(a<b){
		return b/a;
	} else {
		return a/b;
	}
}

