#include <stdio.h>
#include <string.h>
#include <windows.h>
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int number;
    char parOuImpar[30] = "é impar", negativoOuPositivo[30] = "é positivo";
    
    printf("Verifique se seu número é negativo/positivo e par/ímpar.");
    printf("\n\nEscreva seu número: ");
    scanf("%d", &number);

    if (number % 2 == 0){
        strcpy(parOuImpar, "é par");
    }
    if (number < 0){
        strcpy(negativoOuPositivo, "é negativo");
    }
    
    printf("O número %d %s e %s",number,parOuImpar,negativoOuPositivo);
    esperarEnter();
}