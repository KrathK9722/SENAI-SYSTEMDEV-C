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
    int nota[10], maior,menor;
    
    for(int i=0;i<10;i++){
        printf("Digite o %dº número:",i+1);
        scanf("%d",&nota[i]);
        if(i==0){
            maior = nota[i];
            menor = nota[i];
        }
        else{
            if(nota[i]>maior){
                maior = nota[i];
            }
            if(nota[i]<menor){
                menor = nota[i];
            }
        }
    }

    printf("\n\nMaior número: %d",maior);
    printf("\nMenor número: %d",menor);
    esperarEnter();
}