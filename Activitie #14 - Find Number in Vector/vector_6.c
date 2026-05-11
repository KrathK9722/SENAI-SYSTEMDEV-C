#include <stdio.h>
#include <windows.h>

int main(void){
    SetConsoleOutputCP(65001);
    int numero[8] = {15, 42, 8, 73, 29, 61, 4, 37},numeroDigitado;
    
    //Procurar número digitado
    printf("Qual número quer procurar:");
    scanf("%d",&numeroDigitado);

    for(int i=0;i<8;i++){
        if(numero[i] == numeroDigitado){
            printf("Número encontrado na posição %dª.",i+1);
            break;
        }
        else if(i==7){
            printf("Número não foi encontrado");
        }
    }
}