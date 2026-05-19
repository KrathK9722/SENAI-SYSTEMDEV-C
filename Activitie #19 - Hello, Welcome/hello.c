#include <stdio.h>
#include <windows.h>

void saudar(){
    printf("Olá, bem-vindo ao curso de C!");
}

int main(){
    SetConsoleOutputCP(65001);
    saudar();
}