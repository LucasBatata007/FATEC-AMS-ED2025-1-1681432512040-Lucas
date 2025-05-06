/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: S1-B2 Atividade 2                       */
/*             Objetivo: <<        booble sort       >>                              */
/*                                                                                  */
/*                                  Autor: Lucas Batista                            */
/*                                                                    Data:06/05/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void inicializarNumeros(int* numbers, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
}

void bubbleSort(int* numbers, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void exibirNumeros(int* numbers, int n) {
    printf("\nNúmeros em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Quantos números você quer digitar? ");
    scanf("%d", &n);

    int* numbers = (int*) malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    inicializarNumeros(numbers, n);
    bubbleSort(numbers, n);
    exibirNumeros(numbers, n);

    free(numbers);

    return 0;
}
