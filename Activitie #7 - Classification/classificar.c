#include <stdio.h>
#include <windows.h>

int main(void){
    int idade;

    printf("Digite sua idade: ");
    scanf("%d",&idade);
    if(idade > 60){
        printf("Você é idoso");
    }
    else if (idade >= 18 & idade<=59){
        printf("Você é adulto");
    }
    else if(idade >= 0 & idade<=17){
        printf("Você é criança");
    }
    else{
        printf("Idade inválida.");
    }

}