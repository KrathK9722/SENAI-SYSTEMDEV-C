#include <stdio.h>
#include <Windows.h>

int numero;

int quadradoN(int numero){
    return numero * numero;
}
int cuboN(int numero){
    return quadradoN(numero) * numero;
}

int main(){
    SetConsoleOutputCP(65001);
    printf("\n\nDigite seu número: ");
    scanf("%d",&numero);
    printf("%d² = %d   %d³ = %d\n\n",numero,quadradoN(numero),numero,cuboN(numero));
}