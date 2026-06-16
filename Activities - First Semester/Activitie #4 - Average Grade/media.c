#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){

    SetConsoleOutputCP(65001);
    
    //Variaveis
    int nota[8],numeroDigitado;
    float media,soma=0;
    
    //Loop adicionar notas
    for(int i=0;i<8;i++){
        printf("\nDigite a %dª nota:",i+1);
        scanf("%d",&numeroDigitado);
        if((numeroDigitado >=0) & (numeroDigitado<=10)){
            nota[i] = numeroDigitado;
            soma = soma + nota[i];
        }
        else{
            printf("\nValor digitado é inválido");
            i--;
        }
    }
    media = soma / 8; 
    
    //Verifica valor média
    if (media >= 7){
      printf("\nVocê passou de ano com média: %.2f",media);
    }
    else{
      printf("\nVocê passou de ano com média: %.2f",media);
    }
    printf("\nSoma das notas: %.2f",soma);
    printf("\nSua média: %.2f",media);
    esperarEnter();
}