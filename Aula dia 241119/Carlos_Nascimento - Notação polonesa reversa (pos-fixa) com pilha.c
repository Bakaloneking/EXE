#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <math.h>

struct stackNode {
    float data;                 // Armazena números em ponto flutuante
    struct stackNode *nextPtr;  // Ponteiro para o próximo nó
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

// Prototipos
void push(STACKNODEPTR *topPtr, float value);
float pop(STACKNODEPTR *topPtr);
int isEmpty(STACKNODEPTR topPtr);
void instructions(void);
float evaluateRPN(char *expression);

int main() {
	setlocale(LC_ALL,"portuguese");
    char expression[100];
	int i;
	do{
		system("cls");
		printf("Me informe o que deseja acessar:\n\t[1] - Calculadora\n\t[2] - instruções\n\t[3] - Sair\nResposta: "); scanf("%d", &i); getchar();
		switch(i){
			case 1:
				system("cls");
				printf("Digite uma expressão em notação pós-fixada (ex: 5 3 + 2 * ou 10 r):\n");
    			fgets(expression, sizeof(expression), stdin);

    			// Remover o caractere de nova linha, se existir
    			expression[strcspn(expression, "\n")] = '\0';

    			float result = evaluateRPN(expression);

    			printf("O resultado da expressão é: %.2f\n", result);
    			system("pause");
    			break;
    		case 2:
    			instructions();
    			system("pause");
    			break;
    		case 3:
    			exit(1);
				break;
			default:
				printf("Opção errada.");
				break;			
		}
	}while(1);
    return 0;
}

/* Insere um valor no topo da pilha */
void push(STACKNODEPTR *topPtr, float value) {
    STACKNODEPTR newPtr = malloc(sizeof(STACKNODE));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } else {
        printf("Erro: Memória insuficiente para inserir %.2f.\n", value);
        exit(EXIT_FAILURE);
    }
}

/* Remove e retorna o valor do topo da pilha */
float pop(STACKNODEPTR *topPtr) {
    if (isEmpty(*topPtr)) {
        printf("Erro: Tentativa de pop em uma pilha vazia.\n");
        exit(EXIT_FAILURE);
    }

    STACKNODEPTR tempPtr = *topPtr;
    float popValue = tempPtr->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);

    return popValue;
}

/* Verifica se a pilha está vazia */
int isEmpty(STACKNODEPTR topPtr) {
    return topPtr == NULL;
}

/* Avalia uma expressão em notação pós-fixada usando pilha */
float evaluateRPN(char *expression) {
    STACKNODEPTR stack = NULL;
    char *token = strtok(expression, " ");  // Divide a string por espaços

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Token é um número (positivo ou negativo)
            float value = atof(token);
            push(&stack, value);
        } else if (strchr("+-*/^", token[0]) && strlen(token) == 1) {
            // Token é um operador (+, -, *, /)
            if (stack == NULL || stack->nextPtr == NULL) {
                printf("Erro: Expressão inválida.\n");
                exit(EXIT_FAILURE);
            }

            float operand2 = pop(&stack);
            float operand1 = pop(&stack);
            float result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Erro: Divisão por zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                case '^':
                	result = pow(operand1, operand2);
                	break;
                default:
                    printf("Erro: Operador inválido '%s'.\n", token);
                    exit(EXIT_FAILURE);
            }

            push(&stack, result);
            
        } else if(strchr("cstrl",token[0]) && strlen(token) == 1){
        	float operand3 = pop(&stack);
        	float result;
        	switch(token[0]){
        		case 'c':
        			result = cos(operand3);
        			break;
        		case 's':
        			result = sin(operand3);
        			break;
        		case 't':
        			result = tan(operand3);
        			break;
        		case 'r':
        			if(operand3<0){
        				printf("Erro: Não é possivel fazer raiz quadrada de número negativo.\n");
						exit(EXIT_FAILURE);
					}
        			result = sqrt(operand3);
        			break;
        		case 'l':
        			if(operand3<=0){
        				printf("Erro: Não é possivel gerar logaritimo de número negativo.\n");
						exit(EXIT_FAILURE);
					}
        			result = log(operand3);
        			break;
        		default:
                    printf("Erro: Operador inválido '%s'.\n", token);
                    exit(EXIT_FAILURE);
			}
			
        	push(&stack, result);
        	
		} else {
            printf("Erro: Token inválido '%s'.\n", token);
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " ");  // Próximo token
    }

    if (stack == NULL || stack->nextPtr != NULL) {
        printf("Erro: Expressão mal formada.\n");
        exit(EXIT_FAILURE);
    }

    return pop(&stack);  // O resultado final
}

void instructions(void){
	system("cls");
	printf("As operadores possiveis nesta calculadora são:\n\t+ = Soma\n\t- = Subtração\n\t* = Multiplicação\n\t/ = Divisão\n\t"
			"^ = Potencia\nOperadores unitarios:\n\tc = Coseno\n\ts = Seno\n\tt = Tangente\n\tr = Raiz Quadrada\n\tl = Logaritimo\n");
	printf("As operações funcionam do seginte modo:\n\tnumero1 numero2 operador (PRESSIONE ENTER)\n\tEX: 5 3 +\n\t numero1 numero2 operador1 numero3 operador2 (PRESSIONE ENTER)\n\tEX: 5 3 + 2 *\n");
	printf("As operações com os Operadores unitarios devem ser feitas do seginte modo:\n\t numero operadorunitario\n\tEX: 10 r\n\tnumero1 numero2 operador operadorunitario (PRESSIONE ENTER)\n\tEX: 5 3 + r\n\tnumero1 numero2 operador1 numero3 operardor2 operadorunitario (PRESSIONE ENTER)\n\tEX: 5 3 + 2 * r\n");
}
