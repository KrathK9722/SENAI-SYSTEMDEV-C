#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    float preco, valorFinal;
    int quantidade;

    printf("\nDigite o valor do produto: ");
    scanf("%f",&preco);
    printf("Digite a quantidade de itens: ");
    scanf("%d",&quantidade);
    valorFinal = quantidade * preco;
    if(valorFinal >=100){
        valorFinal = valorFinal * 0.95;
        printf("Valor da sua compra ficou: R$%.2f com 5%% de desconto.",valorFinal);
    }
    else{
        printf("Valor da sua compra ficou: R$%.2f",valorFinal);
    }
    esperarEnter();
}