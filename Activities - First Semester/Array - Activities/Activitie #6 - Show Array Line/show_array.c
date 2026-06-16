#include <stdio.h>
#include <windows.h>

#define NL 4
#define NC 5

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
        }
    }
    
    //Select the line
    printf("Write the Array line you want to see (0-3): ");
    do{
        scanf("%d",&aux);
        if (aux != 0 && aux != 1 && aux != 2 && aux != 3){
            printf("Write a valid number between 0 and 3:");
        }
    }while(aux != 0 && aux != 1 && aux != 2 && aux != 3);
    
    //Show the line
    printf("\n======= | Array Entered | =======\n");
    printf("           |COLUMNS|    \n");
    printf(" LINE | 0   1   2   3   4 \n");
    printf("   %02d |[%02d][%02d][%02d][%02d][%02d]\n",aux, array[aux][0],array[aux][1],array[aux][2],array[aux][3],array[aux][4]);
             
    printf("=================================");
    esperarEnter();
}
