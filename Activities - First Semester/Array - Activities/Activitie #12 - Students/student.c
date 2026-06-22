#include <stdio.h>
#include <windows.h>

//Variável global modificavel
int NL, NC;

void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPress ENTER to continue...");
    getchar();
}

int main(){
    SetConsoleOutputCP(65001);

    printf("\nCreating the class");
    printf("\nEnter the number of students:");
    scanf("%d",&NL);
    printf("\nEnter the number of Grades:");
    scanf("%d",&NC);


    float array[NL][NC], average[NL], classGrade = 0;

    //Setando matriz
    for (int i=0;i<NL;i++){
        for (int j=0;j<NC;j++){
            do{
                printf("\nEnter the grade of Student #[%d] | Test #[%d]:",i+1,j+1);
                scanf("%f",&array[i][j] );   
            }while (array[i][j] < 0 || array[i][j] >10);

            if (j == 0)
            {
                average[i] = 0;
            }
            average[i] += array[i][j];
        }
    }
    
    printf("\n======= | CLASS REPORT CARD | =======");
    printf("\nTEST:         ");
    for (int j=0;j<NC;j++){
        printf("%d     ",j+1);
    }
    for (int i=0;i<NL;i++){
        printf("\nStudent #%d: ",i+1);
        for(int j=0;j<NC;j++){
            printf("[%.1f] ",array[i][j]);
        }
        average[i] = average[i]/NC;
        printf("  Final Grade:[%.1f]",average[i]);
        printf("  Status: ");
        if(average[i] >= 7){
            printf("Approved");
        }
        else{
            printf("Disapproved");
        }

    }
    for(int i=0;i<NL;i++){
        classGrade += average[i];
    }
    classGrade = classGrade/NL;
    printf("\nClass average grade: [%.1f]",classGrade);
    printf("\n=================================");
    esperarEnter();
}
