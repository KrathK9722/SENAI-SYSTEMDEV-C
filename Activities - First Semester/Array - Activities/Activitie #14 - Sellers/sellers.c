#include <stdio.h>
#include <windows.h>

//Variabels
#define NC 7
int NL;

//Prototypes
void esperarEnter();
void printMenu();
void showReport(int seller[NL][NC]);
void registerSale(int seller[NL][NC]);
void totalSeller(int seller[NL][NC]);
void totalDay(int seller[NL][NC]);

int main(){
    SetConsoleOutputCP(65001);
    printf("How many sellers you have in your enterprise:");
    scanf("%d",&NL);


    int seller[NL][NC], option = 10;
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            seller[i][j]=0;
        }
    }

    do
    {
        printMenu();
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            registerSale(seller);
            esperarEnter();
            break;
        case 2:
            showReport(seller);
            esperarEnter();
            break;
        case 3:
            totalSeller(seller);
            esperarEnter();
            break;
        case 4:
            totalDay(seller);
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
    printf("\n===========| SELLERS MENU |===========");
    printf("\n1 - Register Sale");
    printf("\n2 - See report");
    printf("\n3 - Total sales per Seller");
    printf("\n4 - Total sales per Day");
    printf("\n0 - Exit");
    printf("\nChoose an option:");
}

//Show seats
void showReport(int seller[NL][NC]){
    printf("\n______________________________________________________________________");
    printf("\n|                                SALES REPORT                        |");
    printf("\n|____________________________________________________________________|");
    printf("\n|WEEKDAY     |   1   |   2   |   3   |   4   |   5   |   6   |   7   |");
    printf("\n|____________|_______|_______|_______|_______|_______|_______|_______|");
    for (int i=0;i<NL;i++){
    printf("\n|Seller ID%03d|",i+1);
        for(int j=0;j<7;j++){
            printf(" R$%03d |",seller[i][j]);
        }
    printf("\n|____________|_______|_______|_______|_______|_______|_______|_______|");
        
    }
    printf("\n|Best sale Day:%d Value:R$%03d                                         |",1,seller[0][0]);
    printf("\n|Best seller: Seller#%03d                                             |",1);
    printf("\n|____________________________________________________________________|");
}

//Reserve seat
void registerSale(int seller[NL][NC]){
    int saveId;
    printf("\nWhich seller's sale do you want to register?");
    printf("\nWrite the seller's ID 1-%d:",NL);
    scanf("%d",&saveId);

}

//Total Seller sales
void totalSeller(int seller[NL][NC]){
    int total;
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            if (seller[i][j] ==  0){
                total++;
            }
        }
    }
    printf("\nThe total amount of released seats is: %d",total);
}

void totalDay(int seller[NL][NC]){}