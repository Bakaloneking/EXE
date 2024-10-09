#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct Pessoa{
	char nome, rua, bair, cida, comp, uf;
	int tel[3], num, cep;
};struct Pessoa pess[3];

int main(){
	setlocale(LC_ALL,"portuguese");
	
}
