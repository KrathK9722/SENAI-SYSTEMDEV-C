//Made a calculator using C, you can run it running the calculadora.exe 




#include <stdio.h> 
#include <windows.h>

float valor[2];
int opcao = -1;

void valorEscolhido() {
    printf("Digite o primeiro valor:\n");
    scanf("%f", &valor[0]);
    printf("Digite o segundo valor:\n");
    scanf("%f", &valor[1]);
}

float calculadora(float a, float b, int operacao) {
    if (operacao == 1) {
        return a + b;
    } 
    else if (operacao == 2) {
        return a - b;
    }    
    else if (operacao == 3) {
        return a * b;
    } 
    else if (operacao == 4) {    
        if (b != 0) {
            return a / b;
        } 
        else {
            printf("Erro: Divisão por zero não é permitida.\n");
            return 0; 
        }
    } 
    else {
        printf("Operação inválida.\n");
        return 0; 

    }
}

void main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    while(opcao != 0) {
        printf("=============== Menu de Cálculadora ===============\n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("0. Sair\n");
        printf("========================================\n");

        printf("Escolha uma opção:\n");
        scanf("%u", &opcao);
        
        if (opcao != 0){
            valorEscolhido();
            printf("Resultado: %.2f\n", calculadora(valor[0], valor[1], opcao));
        }
        else if (opcao == 0) {
            printf("Encerrando a calculadora.\n");
            break;
        }
        else if (opcao < 0 || opcao > 4) {
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            continue;
        }
            
    }
}
