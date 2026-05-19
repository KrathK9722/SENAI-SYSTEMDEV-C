#include <stdio.h>
#include <Windows.h>

//Variaveis
char pessoas[3][30] = {"Ana","Carlos","Beatriz"};



void hello(char nome[]);


int main(){
    SetConsoleOutputCP(65001);
    for(int i=0;i<3;i++){
        hello(pessoas[i]);
    }
}

void hello(char nome[]){
    printf("\nOlá, %s!",nome);
}