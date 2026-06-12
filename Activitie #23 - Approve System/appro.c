#include <stdio.h>
#include <Windows.h>

float lernota(){
    float nota;
    printf("Digite a nota do aluno: ");
    scanf("%f",&nota);
    return nota;
}

char* statusAluno(float nota){
    char *status;
    if (nota >= 7){
         status = "Aprovado";
    }
    else{
         status = "Reprovado";
    }
    return status;
}
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
void imprimirResultado(float nota,char *status){
 printf("Nota: %.2f  Status: %s",nota,status);
}

int main(){
    SetConsoleOutputCP(65001);
    float nota = lernota();
    char *status;
    status = statusAluno(nota);
    imprimirResultado(nota,status);
    esperarEnter();
}
