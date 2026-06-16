#include <stdio.h>
#include <windows.h>

#define NL 6
#define NC 4

//Global variables
int array[NL][NC], aux = 0;

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
            if(array[i][j]%2==0){
                aux += 1;
            }
        }
    }
    
    //Show quantity of even numbers
    printf("Quantity of even numbers in the array: %d",aux);
    
    esperarEnter();
}