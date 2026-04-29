#include <stdio.h>
#include <windows.h>

void main(){
    SetConsoleOutputCP(65001);
    float n,media=0,maior=0,soma=0;

    for (int i=0;i<2;i++){
        printf("Write the %d° number:",i+1);
        scanf("%f", &n);
        
        if (n > maior){
            maior = n;
        }
        soma  += n;

    }
    media = soma / 2;
    
    printf("\n\n============== RESULTS ============\n");
    printf("Total: %.2f",soma);
    printf("\nAverage: %.2f",media);
    printf("\nBiggest Number: %.2f",maior);
    printf("\n====================================");
}
