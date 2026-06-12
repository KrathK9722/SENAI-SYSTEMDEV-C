#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleOutputCP(65001);

    int number[5];
    int i;
    
    //Lendo valores
    for (i=0;i<5;i++){
        printf("Digite o %dº número:",i+1);
        scanf("%d",&number[i]);
    }
   
    //Vetor original
    printf("\n\n====== Valores originais do vetor =====");
    for(i=0;i<5;i++){
        printf("\nValor da %dº posição:%d",i,number[i]);
    }
    
    for(i=0;i<5;i++){
        number[i] = number[i] *2;
    }

    //Vetor dobrado
    printf("\n\n====== Valores do vetor multiplicados por 2 =====");
    for(i=0;i<5;i++){
        printf("\nValor da %dº posição:%d",i,number[i]);
    }
    esperarEnter();
}