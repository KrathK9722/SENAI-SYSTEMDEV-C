#include <stdio.h>
#include <windows.h>

//Global variables
int array[3][4];

void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}

int main(){
    SetConsoleOutputCP(65001);

    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            printf("\nEnter the number of array[%d][%d]:",i,j);
            scanf("%d",&array[i][j]);
        }
    }
    printf("\n======= | Array Entered | =======\n");
    printf("           |COLUMNS|    \n");
    printf(" LINES | 0   1   2   3   \n");
    printf("   0   |[%02d][%02d][%02d][%02d]\n",array[0][0],array[0][1],array[0][2],array[0][3]);
    printf("   1   |[%02d][%02d][%02d][%02d]\n",array[1][0],array[1][1],array[1][2],array[1][3]);
    printf("   2   |[%02d][%02d][%02d][%02d]\n",array[2][0],array[2][1],array[2][2],array[2][3]);          
    printf("=================================");
    esperarEnter();
}