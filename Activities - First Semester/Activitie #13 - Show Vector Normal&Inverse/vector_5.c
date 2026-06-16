#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleOutputCP(65001);
    int numero[6],i;
    
    for(i=0;i<6;i++){
        printf("Digite o %dº número:",i+1);
        scanf("%d",&numero[i]);
    }

    printf("\nVetor na ordem original:{");
    for(i=0;i<6;i++){
        if(i!=5){
            printf("%d,",numero[i]);
        }
        else{
            printf("%d}",numero[i]);
        }
    }
    printf("\nVetor na ordem inversa:{");
    for(i=5;i>=0;i--){
        if(i!=0){
            printf("%d,",numero[i]);
        }
        else{
            printf("%d}",numero[i]);
        }
    }
    esperarEnter();

}