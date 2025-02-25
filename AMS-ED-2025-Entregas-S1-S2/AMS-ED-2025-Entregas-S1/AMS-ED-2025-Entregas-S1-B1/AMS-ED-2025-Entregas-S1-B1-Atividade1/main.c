#include <stdio.h>


typedef struct {
    float ValorOrigin;
    float aplicado;
    float desconto;
    int tipo;
} ObjetoRetornodoCalculo;

ObjetoRetornodoCalculo CalculadoraDesconto(float *valor,int *tipo,float *desconto){
    
   ObjetoRetornodoCalculo Obj; 
   Obj.ValorOrigin = *valor;
   Obj.tipo = *tipo;
   
  if(*tipo == 1){
      Obj.aplicado = (100 - *desconto)/100 * *valor;
      Obj.desconto = Obj.ValorOrigin - Obj.aplicado;
      return Obj;
  }else{
      Obj.aplicado = Obj.ValorOrigin - *desconto;
      Obj.desconto = *desconto /(Obj.ValorOrigin/100);
      return Obj;
  }
    
}




void ExibirValorCalculado(ObjetoRetornodoCalculo Obj) {
    printf("Valor Original: %.2f\n", Obj.ValorOrigin);
    printf("Valor com Desconto aplicado: %.2f\n", Obj.aplicado);
    if(Obj.tipo == 0){
         printf("Seu desconto em porcentagem é: %.2f%%\n", Obj.desconto);
    }else{
         printf("Seu desconto em reais é: R$%.2f\n", Obj.desconto);

    }
}

void ExibirPerguntaValor(float *vl) {
   while (*vl <= 0){
        printf("Insira o valor do seu produto: ");
        scanf("%f", vl);
        if (*vl <= 0) {
            printf("O valor não pode ser negativo ou zero. Tente novamente.\n");
        }
    } 
}

void ExibirPerguntaTipo(int *tp) {
    while (*tp != 0 && *tp != 1){
        printf("Você gostaria de adicionar um desconto em porcentagem ou em reais \n");
        printf("Use 1 para porcentagem e 0 para reais: ");
        scanf("%i", tp);
        if (*tp != 0 && *tp != 1) {
            printf("O valor deve ser somente 0 ou 1. Tente novamente.\n");
        }
    } 
}



void VerificacaoDesconto(float *valor, int *tipo, float *desconto){
    while (*desconto < 0 || (*tipo == 1 && *desconto >= 100) || (*tipo == 0 && *desconto > *valor)){
        if(*tipo == 1){ 
            if (*desconto < 0 || *desconto >= 100) {
                printf("O desconto em porcentagem deve ser maior ou igual a 0 e menor que 100. Tente novamente.\n");
            }
        }else{ 
            if(*desconto < 0 || *desconto > *valor){
                printf("O desconto em reais não pode ser negativo e não pode ser maior que o valor do produto. Tente novamente.\n");
            }
        }
       
        if(*desconto < 0 || (*tipo == 1 && *desconto >= 100) || (*tipo == 0 && *desconto > *valor)) {
            if(*tipo == 1){
                printf("Digite seu desconto em porcentagem (menos que 100): ");
            } else {
                printf("Digite seu desconto em reais (não maior que o valor do produto): ");
            }
            scanf("%f", desconto);
        }
    } 
}

void main()
{
    float valor,desconto = -1;
    int tipo = -1;
    
    ExibirPerguntaValor(&valor);

    ExibirPerguntaTipo(&tipo);

    VerificacaoDesconto(&valor,&tipo,&desconto);
    
    
  
    ObjetoRetornodoCalculo Obj = CalculadoraDesconto(&valor, &tipo, &desconto);
    ExibirValorCalculado(Obj);


}