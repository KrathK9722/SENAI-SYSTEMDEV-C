#include <stdio.h>
#include <windows.h>

void main(){

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    float nota[3],media,soma=0;
    
    for(int i=0;i<=2;i++){
      printf("Digite sua %d° nota: ",i+1);
      scanf("%f", &nota[i]);

      soma = soma + nota[i];
    }

    media = soma / 3; 

    if (media >= 7){
      printf("\nVocê passou de ano com média: %.2f",media);
      printf("\nNota #1: %.2f",nota[0]);
      printf("\nNota #2: %.2f",nota[1]);
      printf("\nNota #3: %.2f",nota[2]);
    }
    else{
      printf("\nVocê não passou de ano, sua média foi: %.2f",media);
      printf("\nNota #1: %.2f",nota[0]);
      printf("\nNota #2: %.2f",nota[1]);
      printf("\nNota #3: %.2f",nota[2]);
    }
}
