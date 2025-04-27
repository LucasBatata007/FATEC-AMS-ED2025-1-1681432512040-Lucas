/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: S1-B1 Atividade 5                       */
/*             Objetivo: << pilha  >>                                               */
/*                                                                                  */
/*                                  Autor: Lucas Batista                            */
/*                                                                    Data:01/04/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 4

typedef struct {
    float dados[MAX];
    int topo;
} Pilha;

char amaz[1000];  

Pilha* criar_pilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = -1;
    for (int i = 0; i < MAX; i++) {
        p->dados[i] = 0;
    }
    return p;
}

void push(Pilha *p, float valor) {
    if (p->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++p->topo] = valor;
}

float pop(Pilha *p) {
    if (p->topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    return p->dados[p->topo--];
}

float topo(Pilha *p) {
    if (p->topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    return p->dados[p->topo];
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void exibir_memoria(Pilha *p) {
    printf("X: %.2f  Y: %.2f  Z: %.2f  T: %.2f\n",
    p->dados[0], p->dados[1], p->dados[2], p->dados[3]);
}

void realizar_operacao(Pilha *p, char operador) {
    float b = pop(p);
    float a = pop(p);
    float resultado;

    switch (operador) {
        case '+': resultado = a + b; break;
        case '-': resultado = a - b; break;
        case '*': resultado = a * b; break;
        case '/': 
            if (b == 0) {
                printf("Erro: Divisão por zero!\n");
                return;
            }
            resultado = a / b; break;
        default: 
            printf("Operador inválido!\n");
            return;
    }

    push(p, resultado);
    printf("Resultado da operação: %.2f\n", resultado);
}

int main() {
    Pilha *p = criar_pilha();
    char entrada[10];
    
    printf("Modo de entrada: Digite números e operadores separadamente\n");
    printf("Digite 'q' para sair.\n");

    amaz[0] = '\0';

    while (1) {
        printf("\nDigite um número ou operador (+, -, *, /): ");
        scanf("%s", entrada);

        if (entrada[0] == 'q') {
            break;
        }

        if (isdigit(entrada[0])) {
            float numero = atof(entrada);
            push(p, numero);
            char temp[50];
            sprintf(temp, "%.2f", numero);
            strcat(amaz, temp);
            strcat(amaz, " ");  
            printf("Número adicionado à pilha.\n");

        } else if (entrada[0] == '+' || entrada[0] == '-' || 
                   entrada[0] == '*' || entrada[0] == '/') {
            realizar_operacao(p, entrada[0]);
            char operador[2] = {entrada[0], '\0'};
            strcat(amaz, operador);
            strcat(amaz, " "); 

        } else {
            printf("Entrada inválida. Digite um número ou um operador válido.\n");
        }
    }

    exibir_memoria(p);
    printf("Fórmula em notação reversa polonesa: %s\n", amaz);
    
    printf("Resultado final: %.2f\n", topo(p));

    free(p);
    return 0;
}
