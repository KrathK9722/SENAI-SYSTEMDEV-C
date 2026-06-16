#include <stdio.h>
#include <windows.h>

#define NL 3
#define NC 3

//Global variables
int array[NL][NC], aux = 0;
int total_numbers = NL * NC; // Calculate the total amount of numbers in the array

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
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
                aux += array[i][j];
        }
    }

    printf("Sum: %d",aux);
    printf("Average: %d",aux/total_numbers);
    esperarEnter();
}