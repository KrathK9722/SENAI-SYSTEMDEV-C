
/*
This is a simple code to create a list of students who passed or failed. 
I tried to make this code only using basic code without string library or any struct

Date: 2026/05/11
Creator: KrathK - Arthur Kochan
*/


#include <stdio.h>
#include <windows.h>

void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleOutputCP(65001);

    //Variaveis
    float nota[5];
    char aluno[5][50];
    int i;
    
    //Ler alunos e notas
    for(i=0;i<5;i++){
        printf("Escreva o nome do %dº aluno:",i+1);
        scanf("%s",aluno[i]);
    }
    for(i=0;i<5;i++){
        printf("Escreva a nota do aluno %s:",aluno[i]);
        scanf("%f",&nota[i]);
    }

    printf("\n\n======== Resumo da avaliação ========\n");

    //Alunos aprovados
    printf("\nAprovados:");
    for(i=0;i<5;i++){
        if (nota[i] >= 6){
          printf("\n%s",aluno[i]);
        }
    }   

    //Alunos reprovados
    printf("\n\nReprovados:");
    for(i=0;i<5;i++){
        if (nota[i] < 6){
          printf("\n%s",aluno[i]);
        }
    }
    esperarEnter();

}