#include <stdio.h>

void main(){
    char nome[30];
    int idade;
    float altura;
    char text[60];

    printf("Write your name: ");
    fgets(nome, 50, stdin);

    printf("Write your age: ");
    scanf("%d", &idade);

    printf("Write your height: ");
    scanf("%f", &altura);
    
    if(idade >= 18){
        text == "You're 18 years of age or older.";   
    } else if(idade >= 0 & idade <18){
        text == "You're under 18 years.";
    } else{
        text == "You entered an invalid age.";
    }

    printf("\n\n============ YOUR ACCOUNT INFO ===================");
    printf("\nUsername: %s", nome);
    printf("Age: %d years", idade);
    printf("\nHeight: %.2f", altura);
    printf("\n===================================================");
}
