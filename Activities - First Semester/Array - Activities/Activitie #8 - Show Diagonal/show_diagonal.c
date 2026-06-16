#include <stdio.h>
#include <windows.h>

//Variável global modificavel
int NL, NC;

void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}

int main(){
    SetConsoleOutputCP(65001);

    printf("\nCreating the array");
    printf("\nEnter the number of Lines:");
    scanf("%d",&NL);
    printf("\nEnter the number of Columns");
    printf("\nIt is recommended to use the same value as the number of Lines:");
    scanf("%d",&NC);

    int array[NL][NC];

    //Setando matriz
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            printf("\nEnter the number of array[%d][%d]:",i,j);
            scanf("%d",&array[i][j]);
        }
    }
    
    //Show Diagonal
    if (NL == NC){
        int i=0,j=0;
        printf("\n======= | Array Main Diagonal | =======");
        do
        {
            if(i==j){
                printf("\nArray[%d][%d]: %d",i,j,array[i][j]);
            }
            i++;
            j++;
        } while (i < NL && j < NC);
        printf("\n=================================");
        }
    else{
        printf("\nThis array is not a square like 3x3 so you can only visualize the entire array.\n\n");
        printf("\nColumn:  ");
        for (int j=0;j<NC;j++){
            printf("%d   ",j);
        }
        for (int i=0;i<NL;i++){
            printf("\nLine %d: ",i);
            for(int j=0;j<NC;j++){
                printf("[%d] ",array[i][j]);
            }

        }
        
    }

    esperarEnter();
}
