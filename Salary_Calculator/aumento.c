#include <stdio.h>
#include <windows.h>

void main (){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    float salario;
    int anos;
    float aumento;
    float salarioNovo;
    float aumentoTotal = 0;
    
    printf("\n\n\n\n\n======= Cálculo de salário =======");
    printf("\nDigite seu salário atual: ");
    scanf("%f",&salario);
    salarioNovo = salario;
    printf("\nTem quantos anos de empresa? ");
    scanf("%d",&anos);
    printf("\n=================================");
    
    if (anos > 5){
        for (int i=0;i<anos / 5;i++){
            aumento = salarioNovo * 0.10;
            salarioNovo = salarioNovo + aumento;
            aumentoTotal = aumentoTotal + aumento;
        }
    
        printf("\n\nVocê recebera um aumento de R$ %.2f por trabalhar aqui a %d anos, mudando seu salário de R$ %.2f para R$ %.2f", 
        aumentoTotal, anos, salario, salarioNovo);
        }
    else if (anos > 0 & anos < 5){
        printf("\n\nSeu salário não foi alterado porque você não possui mais de 5 anos de trabalho. Salário: %.2f",salario);
    }
    else{
        printf("\n\nTempo de trabalho menor que 0 não é permitido.");
    }
}
