#include <stdio.h>

typedef struct{
    char nome[100];
    float PE[4];
    float AC[5];
    float PP[10];
    float EB[3];
    float NotaFinal;
}candidato;

    
void receberNome(Candidato *candidato) {
    printf("Digite o nome: ");
    scanf("%99s", candidato->nome);
}





float somarNotasCentrais(float *notas, int *indice) {
    float maior = notas[0], menor = notas[0], soma = 0;
    int indiceMaior = 0, indiceMenor = 0;


    for (int i = 1; i < *indice; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
            indiceMaior = i;
        }
        if (notas[i] < menor) {
            menor = notas[i];
            indiceMenor = i;
        }
    }

    
    for (int i = 0; i < *indice; i++) {
        if (i != indiceMaior && i != indiceMenor) {
            soma += notas[i];
        }
    }

    return soma;
}

int main() {
    
    
    
    
    
    
    
    float notas[] = {7.5, 8.0, 9.0, 6.0, 8.5};
    int tamanho = sizeof(notas) / sizeof(notas[0]);

    printf("Soma das notas centrais: %.2f\n", somarNotasCentrais(notas, &tamanho));

    return 0;
}
