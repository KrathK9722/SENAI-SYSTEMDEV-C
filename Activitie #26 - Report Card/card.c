#include <stdio.h>
#include <Windows.h>

float notas[5];

void lerNota(){
   for (int i=0;i<5;i++){
        printf("Digite a nota do %dº aluno: ",i+1);
        scanf("%f",&notas[i]);
   }
}
char* status(int n){
    char *status;
    if (n >= 7){
        status = "AP";
    }
    else if (n < 7){
        status = "RE";
    }
    else {
        status = "Inválido";
    }
    return status;
}
float calMedia(){
    float soma=0;
    for (int i=0;i<5;i++){
        soma = soma + notas[i];
    }
    return soma/5;
}
int calAprovados(){
    int aprov;
    for (int i=0;i<5;i++){
        if (notas[i] >= 7){
            aprov++;
        }
    }
    return aprov;
}


void imprimirBoletim(){
    for (int i=0;i<5;i++){
        printf("\nAluno: 0%d   Nota:%.2f   Status:%s",i,notas[i],status(notas[i]));
    }
    printf("\nMédia da turma foi: %.2f",calMedia());
    printf("\nO número de alunos aprovados foi: %d",calAprovados());
}


int main(){
    SetConsoleOutputCP(65001);
    lerNota();
    imprimirBoletim();
}