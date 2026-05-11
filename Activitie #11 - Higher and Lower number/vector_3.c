#include <stdio.h>
#include <windows.h>

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

    printf("Maior número: %d",maior);
    printf("Menor número: %d",menor);
}