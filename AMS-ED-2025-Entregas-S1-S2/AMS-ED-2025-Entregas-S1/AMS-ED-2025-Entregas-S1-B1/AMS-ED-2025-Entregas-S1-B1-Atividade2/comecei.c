#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    float *PE;
    float *AC;
    float *PP;
    float *EB;
    float notaFinal; 
} Candidato;

void receberNome(Candidato *candidato) {
    printf("Digite o nome: ");
    scanf("%s", candidato->nome); 
}

void receberNotas(float **notas, int quantidade, const char *tipo) {
    *notas = (float *)malloc(quantidade * sizeof(float));
    if (*notas == NULL) {
        printf("Erro ao alocar memória para as notas de %s.\n", tipo);
        exit(1);
    }
    printf("Digite as %d notas para %s:\n", quantidade, tipo);
    for (int i = 0; i < quantidade; i++) {
        do {
            printf("Nota %d: ", i + 1);
            scanf("%f", &(*notas)[i]);
            if ((*notas)[i] < 0 || (*notas)[i] > 10) {
                printf("Nota inválida. A nota deve ser entre 0 e 10.\n");
            }
        } while ((*notas)[i] < 0 || (*notas)[i] > 10); 
    }
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

int compararNotas(const void *a, const void *b) {
    float notaA = ((Candidato *)a)->notaFinal;
    float notaB = ((Candidato *)b)->notaFinal;
    return (notaB - notaA) > 0 ? 1 : -1; 
}

int main() {
    int numCandidatos;

    do {
        printf("Quantos candidatos vão ser avaliados? (Máximo 50): ");
        scanf("%d", &numCandidatos);
        if (numCandidatos <= 0 || numCandidatos > 50) {
            printf("Por favor, insira um número de candidatos entre 1 e 50.\n");
        }
    } while (numCandidatos <= 0 || numCandidatos > 50);

    Candidato *candidatos = (Candidato *)malloc(numCandidatos * sizeof(Candidato));
    if (candidatos == NULL) {
        printf("Erro ao alocar memória para os candidatos.\n");
        exit(1);
    }

    for (int i = 0; i < numCandidatos; i++) {
        printf("\n--- Candidato %d ---\n", i + 1);
        receberNome(&candidatos[i]);
        receberNotas(&candidatos[i].PE, 4, "Prova Escrita (PE)");
        receberNotas(&candidatos[i].AC, 5, "Análise Curricular (AC)");
        receberNotas(&candidatos[i].PP, 10, "Prova Prática (PP)");
        receberNotas(&candidatos[i].EB, 3, "Entrevista em Banca (EB)");

        int tamanhoPE = 4, tamanhoAC = 5, tamanhoPP = 10, tamanhoEB = 3;
        float somaPE = somarNotasCentrais(candidatos[i].PE, &tamanhoPE);
        float somaAC = somarNotasCentrais(candidatos[i].AC, &tamanhoAC);
        float somaPP = somarNotasCentrais(candidatos[i].PP, &tamanhoPP);
        float somaEB = somarNotasCentrais(candidatos[i].EB, &tamanhoEB);

        candidatos[i].notaFinal = (somaPE * 0.3) + (somaAC * 0.1) + (somaPP * 0.4) + (somaEB * 0.2);
    }


    qsort(candidatos, numCandidatos, sizeof(Candidato), compararNotas);

    printf("\n--- Top 5 Melhores Candidatos ---\n");
    for (int i = 0; i < (numCandidatos < 5 ? numCandidatos : 5); i++) {
        printf("%dº lugar - %s: %.2f\n", i + 1, candidatos[i].nome, candidatos[i].notaFinal);

        free(candidatos[i].PE);
        free(candidatos[i].AC);
        free(candidatos[i].PP);
        free(candidatos[i].EB);
    }

    free(candidatos);

    return 0;
}
