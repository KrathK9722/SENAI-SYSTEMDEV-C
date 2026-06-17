#include <stdio.h>
#include <windows.h>

//Variável global modificavel
#define NL 3
#define NC 5

//Protótipos
void waitEnter();
void menu();
void enteringNumbers(int enterprise[NL][NC]);
void showArray(int enterprise[NL][NC]);
void showBiggest(int enterprise[NL][NC]);
void sumArray(int enterprise[NL][NC]);
void clean();

// ===============
//  MAIN FUNCTION
// ===============
int main(){
    SetConsoleOutputCP(65001);
    
    int enterprise[NL][NC], option=0; 
    int filled = 0;

    do{
        clean();
        menu();
        scanf("%d",&option);
        switch(option){
            case 1:
                clean();
                enteringNumbers();
                filled = 1;
                waitEnter();
                break;
            case 2:
                clean();
                if(filled == 1){
                    showArray(enterprise);
                }
                else{
                    printf("Fill the array first...");
                }
                waitEnter();
                break;
            case 3:
                clean();
                if(filled == 1){
                    showBiggest(enterprise);
                }
                else{
                    printf("Fill the array first...");
                }
                waitEnter();
                break;
            case 4:
                clean();
                if(filled == 1){
                    sumArray(enterprise);
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
void enteringNumbers(int enterprise[NL][NC]){
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            printf("\nEnter the product #%d quantity of the branch #%d [%d]:",j,i);
            scanf("%d",&enterprise[i][j]);
        }
    }
}
void menu(){
    printf("\n====== ENTERPRISE ======");
    printf("\n1 - Fill inventory");
    printf("\n2 - Show inventory");
    printf("\n3 - Sum total inventory");
    printf("\n0 - Sair do menu");
    printf("\nSelect an option: ");
}
void showArray(int enterprise[NL][NC]){
        printf("\nColumn:  ");
        for (int j=0;j<NC;j++){
            printf("%d   ",j);
        }
        for (int i=0;i<NL;i++){
            printf("\nLine %d: ",i);
            for(int j=0;j<NC;j++){
                printf("[%d] ",enterprise[i][j]);
            }

        }
}
void sumArray(int enterprise[NL][NC]){
    int aux[NL], total=0;
    for(int i=0;i<NL;i++){
        aux[i] = 0;
    }
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
             aux[i] += enterprise[i][j];
             total += enterprise[i][j];
            }
        }
    for(int i=0;i<NL;i++){
        printf("\nTotal inventory Branch #%d+1: %d",i,aux[i]);
    }
    printf("\nTotal Enterprise stock: %d",total);
}