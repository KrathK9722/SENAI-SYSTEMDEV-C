#include <stdio.h>
#include <Windows.h>

//Variaveis
char pessoas[3][30] = {"Ana","Carlos","Beatriz"};

void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}

//Protótipo da função
void hello(char nome[]);


int main(){
    SetConsoleOutputCP(65001);
    for(int i=0;i<3;i++){
        hello(pessoas[i]);
    }
}

// Função
void hello(char nome[]){
    printf("\nOlá, %s!",nome);
}