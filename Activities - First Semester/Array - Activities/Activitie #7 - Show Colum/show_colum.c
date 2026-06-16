#include <stdio.h>
#include <windows.h>

#define NL 5
#define NC 3

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
    printf("Write the Array Column you want to see (0-2): ");
    do{
        scanf("%d",&aux);
        if (aux != 0 && aux != 1 && aux != 2 && aux != 3){
            printf("Write a valid number between 0 and 3:");
        }
    }while(aux != 0 && aux != 1 && aux != 2 && aux != 3);
    
    //Show the line
    printf("\n======= | Array Entered | =======\n");
    printf("      |COLUMN|    \n");
    printf(" LINE |  %d | \n",aux);
    printf("   0  |[%02d]|\n",array[0][aux]);
    printf("   1  |[%02d]|\n",array[1][aux]);
    printf("   2  |[%02d]|\n",array[2][aux]);
    printf("   3  |[%02d]|\n",array[3][aux]);
    printf("   4  |[%02d]|\n",array[4][aux]);    
    printf("=================================");
    esperarEnter();
}
