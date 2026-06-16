#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
void saudar(){
    printf("Olá, bem-vindo ao curso de C!");
}

int main(){
    SetConsoleOutputCP(65001);
    saudar();
    esperarEnter();
}