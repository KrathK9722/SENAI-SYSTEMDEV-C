#include <stdio.h>
#include <windows.h>

//Variabels
#define NC 7
int NL;

//Prototypes
void esperarEnter();
void printMenu();
void showReport(int salesperson[NL][NC]);
void registerSale(int salesperson[NL][NC]);
void totalSalesperson(int salesperson[NL][NC]);
void totalDay(int salesperson[NL][NC]);

int main(){
    SetConsoleOutputCP(65001);
    printf("How many salespeople do you have in your company:");
    scanf("%d",&NL);


    int salesperson[NL][NC], option = 10;
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            salesperson[i][j]=0;
        }
    }

    do
    {
        printMenu();
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            registerSale(salesperson);
            esperarEnter();
            break;
        case 2:
            showReport(salesperson);
            esperarEnter();
            break;
        case 3:
            totalSalesperson(salesperson);
            esperarEnter();
            break;
        case 4:
            totalDay(salesperson);
            esperarEnter();
            break;
        case 0:
            break;
        default:
            printf("Invalid Option");
            esperarEnter();
            break;
        }
    } while (option != 0);
    

    esperarEnter();
}

//Wait enter
void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPress ENTER to continue...");
    getchar();
}

//Visual Menu
void printMenu(){
    printf("\n===========| SALES MENU |===========");
    printf("\n1 - Register Sale");
    printf("\n2 - See report");
    printf("\n3 - Total sales per Salesperson");
    printf("\n4 - Total sales per Day");
    printf("\n0 - Exit");
    printf("\nChoose an option:");
}

//Show seats
void showReport(int salesperson[NL][NC]){
    int bestSalesperson=0,bestSale=-1, bestDay=0, salespersonLastTotal=0;
    for(int i=0;i<NL;i++){
        int salespersonTotal = 0;
        for(int j=0;j<NC;j++){
            if(salesperson[i][j]>bestSale){
                bestSale = salesperson[i][j];
                bestDay = j;
            }
            salespersonTotal += salesperson[i][j];
        }
        if(salespersonTotal > salespersonLastTotal){
            salespersonLastTotal = salespersonTotal;
            bestSalesperson = i;
        }
    }

    printf("\n______________________________________________________________________");
    printf("\n|                                SALES REPORT                        |");
    printf("\n|____________________________________________________________________|");
    printf("\n|WEEKDAY     |   1   |   2   |   3   |   4   |   5   |   6   |   7   |");
    printf("\n|____________|_______|_______|_______|_______|_______|_______|_______|");
    for (int i=0;i<NL;i++){
    printf("\n|Person ID%03d|",i+1);
        for(int j=0;j<7;j++){
            printf(" R$%03d |",salesperson[i][j]);
        }
    printf("\n|____________|_______|_______|_______|_______|_______|_______|_______|");
        
    }
    printf("\n|Best sale: R$%03d Made on day: %01d                                     |",bestSale,bestDay+1);
    printf("\n|Best salesperson: Salesperson ID%03d                                 |",bestSalesperson+1);
    printf("\n|____________________________________________________________________|");
}

//Reserve seat
void registerSale(int salesperson[NL][NC]){
    char idWrited[100];
    int saveId,saveDay,value;
    printf("\nWhich salesperson's sale do you want to register? ");
    printf("\nWrite the salesperson's ID 1-%d:",NL);
    scanf("%s",idWrited);
    for (long long unsigned int i = 0; i < strlen(idWrited); i++) {
        if (!isdigit(idWrited[i])) {
            printf("\nError: write just integral numbers!\n");
            return;
        }
    }
    saveId = atoi(idWrited);

    do{
        printf("\nThis sale was made on which day of the weekend?");
        printf("\n1-Sunday");
        printf("\n2-Monday");
        printf("\n3-Tuesday");
        printf("\n4-Wednesday");
        printf("\n5-Thursday");
        printf("\n6-Friday");
        printf("\n7-Saturday");
        printf("\nChoose a number:");
        scanf("%d",&saveDay);
        if(saveDay <1 || saveDay >7){
            printf("\nChoose a valid date!");
        }
    }while(saveDay <1 || saveDay >7);

    do{
        printf("\nWhat was the amount of the sale? ");
        scanf("%d",&value);
        if(value > 0){
            salesperson[saveId-1][saveDay-1] = value;
            printf("\nSale saved!");
        }
        else{
            printf("\nWrite a valid value!");
        }
    }while(value<=0);
}

//Total Salesperson sales
void totalSalesperson(int salesperson[NL][NC]){
    int totalSale[NL];
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            if(j == 0){
                totalSale[i] = 0;
            }
            else{
                totalSale[i] += salesperson[i][j];
            }
        }
    }
    printf("\n========= TOTAL REVENUE PER SALESPERSON ========");
    for(int i=0;i<NL;i++){
        printf("\nSalesperson ID%03d| TOTAL VALUE:R$%01d",i+1,totalSale[i]);
    }
    printf("\n====================================================");
}

void totalDay(int salesperson[NL][NC]){
    int totalSale[7];
    for(int j=0;j<NC;j++){
        for(int i=0;i<NL;i++){
            if(i == 0){
                totalSale[j] = 0;
            }
            else{
                totalSale[j] += salesperson[i][j];
            }
        }
    }
    printf("\n======== TOTAL VALUE ON EACH DAY ========");
    printf("\nSunday: R$%01d",totalSale[0]);
    printf("\nMonday: R$%01d",totalSale[1]);
    printf("\nTuesday: R$%01d",totalSale[2]);
    printf("\nWednesday: R$%01d",totalSale[3]);
    printf("\nThursday: R$%01d",totalSale[4]);
    printf("\nFriday: R$%01d",totalSale[5]);
    printf("\nSaturday: R$%01d",totalSale[6]);
    printf("\n=========================================");
}
