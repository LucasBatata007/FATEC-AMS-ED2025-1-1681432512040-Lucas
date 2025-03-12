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








#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    float *PE;
    float *AC;
    float *PP;
    float *EB;
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



int main() {
    Candidato candidatos[2];

    for (int i = 0; i < 2; i++) {
        printf("\n--- Candidato %d ---\n", i + 1);
        receberNome(&candidatos[i]);
        receberNotas(&candidatos[i].PE, 4, "Prova Escrita (PE)");
        receberNotas(&candidatos[i].AC, 5, "Análise Curricular (AC)");
        receberNotas(&candidatos[i].PP, 10, "Prova Prática (PP)");
        receberNotas(&candidatos[i].EB, 3, "Entrevista em Banca (EB)");
    }

    for (int i = 0; i < 2; i++) {
        printf("\nCandidato: %s\n", candidatos[i].nome);
        printf("Notas PE: ");
        for (int j = 0; j < 4; j++) printf("%.1f ", candidatos[i].PE[j]);

        printf("\nNotas AC: ");
        for (int j = 0; j < 5; j++) printf("%.1f ", candidatos[i].AC[j]);

        printf("\nNotas PP: ");
        for (int j = 0; j < 10; j++) printf("%.1f ", candidatos[i].PP[j]);

        printf("\nNotas EB: ");
        for (int j = 0; j < 3; j++) printf("%.1f ", candidatos[i].EB[j]);

        free(candidatos[i].PE);
        free(candidatos[i].AC);
        free(candidatos[i].PP);
        free(candidatos[i].EB);
    }

    return 0;
}
