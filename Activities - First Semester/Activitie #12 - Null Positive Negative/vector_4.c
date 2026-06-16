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
    int numero[10], positivo=0,negativo=0,nulo=0;
    
    for(int i=0;i<10;i++){
        printf("Digite o %dº número:",i+1);
        scanf("%d",&numero[i]);
        if(numero[i]==0){
            nulo++;
        }
        else if(numero[i]>0){
            positivo++;
        }
        else {
            negativo++;
        }
    }

    printf("\n\nPositivos: %d",positivo);
    printf("\nNegativos %d",negativo);
    printf("\nNulos %d",nulo);
    esperarEnter();
}