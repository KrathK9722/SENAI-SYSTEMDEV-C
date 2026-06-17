#include <stdio.h>
#include <windows.h>

//Variável global modificavel
#define NL 5
#define NC 5

//Protótipos
void waitEnter();
void menu();
void enteringNumbers(int array[NL][NC]);
void showArray(int array[NL][NC]);
void showBiggest(int array[NL][NC]);
void sumArray(int array[NL][NC]);
void clean();

// ===============
//  MAIN FUNCTION
// ===============
int main(){
    SetConsoleOutputCP(65001);
    
    int array[NL][NC], option=0; 
    int filled = 0;

    do{
        clean();
        menu();
        scanf("%d",&option);
        switch(option){
            case 1:
                clean();
                if(filled == 1){
                    enteringNumbers(array);
                    filled = 1;
                }
                else{
                    printf("Fill the array first...");
                }
                waitEnter();
                break;
            case 2:
                clean();
                if(filled == 1){
                    showArray(array);
                }
                else{
                    printf("Fill the array first...");
                }
                waitEnter();
                break;
            case 3:
                clean();
                if(filled == 1){
                    showBiggest(array);
                }
                else{
                    printf("Fill the array first...");
                }
                waitEnter();
                break;
            case 4:
                clean();
                if(filled == 1){
                    sumArray(array);
                }
                else{
                    printf("Fill the array first...");
                }
                waitEnter();
                break;
            case 0: 
                break;
            default:
                continue;
        }
    }while (option != 0);
    clean();
    printf("Exiting system...");
    waitEnter();
}

//Funções
void clean(){
    printf("\e[1;1H\e[2J");
}
void waitEnter()
{
    while (getchar() != '\n'); 
    printf("\nPress ENTER to continue...");
    getchar();
}
void enteringNumbers(int array[NL][NC]){
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            printf("\nEnter the number of array[%d][%d]:",i,j);
            scanf("%d",&array[i][j]);
        }
    }
}
void menu(){
    printf("\n====== ARRAYS ======");
    printf("\n1 - Fill array");
    printf("\n2 - Show array");
    printf("\n3 - Show biggest number");
    printf("\n4 - Sum array numbers");
    printf("\n0 - Sair do menu");
    printf("\nSelect an option: ");
}
void showArray(int array[NL][NC]){
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
void showBiggest(int array[NL][NC]){
    int biggest = array[0][0];
    int x=0,y=0;

    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            if (array[i][j] > biggest){
                biggest = array[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("\nThe biggest number is: %d", biggest);
    printf("\nPosition in the array: [%d][%d]",x,y);
}
void sumArray(int array[NL][NC]){
    int aux = 0;

    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
             aux += array[i][j];
            }
        }
    printf("The array sum is: %d", aux);
}