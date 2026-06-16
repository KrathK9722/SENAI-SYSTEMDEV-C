#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleOutputCP(65001);
    
    float vet[5],numeroDigitado;

    for(int i=0;i<5;i++){

        printf("\nDigite a %dª nota:",i+1);
        scanf("%f",&numeroDigitado);

        if(numeroDigitado >=0 & numeroDigitado<=10){
            vet[i] = numeroDigitado;
        }
        else{
            printf("\nValor digitado é inválido");
            i--;
        }

    }

    printf("\n\n===== BOLETIM =====");
    for(int i=0;i<5;i++){
        printf("\n%dª nota:%.2f",i+1,vet[i]);
    }
    printf("\n===================");
    esperarEnter();
}