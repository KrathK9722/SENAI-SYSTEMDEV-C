#include <stdio.h>
#include <windows.h>

#define NL 4
#define NC 4

//Global variables
int array[NL][NC], biggest;

void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}

int main(){
    SetConsoleOutputCP(65001);

    //Setando matriz
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            printf("\nEnter the number of array[%d][%d]:",i,j);
            scanf("%d",&array[i][j]);
        }
    }
    
    //Soma dos valores
    biggest = array[0][0];
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            if(array[i][j] > biggest)
                biggest = array[i][j];
        }
    }

    printf("Biggest number:",biggest);
    esperarEnter();
}