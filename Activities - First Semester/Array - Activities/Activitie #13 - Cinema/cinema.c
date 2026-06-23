#include <stdio.h>
#include <windows.h>

//Variável global modificavel
#define NL 6
#define NC 8

//Prototypes
void esperarEnter();
void printMenu();
void showRoom(int seat[NL][NC]);
void reserveSeat(int seat[NL][NC]);
void freeSeat(int seat[NL][NC]);
void total(int seat[NL][NC]);

int main(){
    SetConsoleOutputCP(65001);
    int seat[NL][NC], option = 10;
    for (int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            seat[i][j] = 0;
        }
    }

    do
    {
        printMenu();
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            showRoom(seat);
            reserveSeat(seat);
            esperarEnter();
            break;
        case 2:
            showRoom(seat);
            freeSeat(seat);
            esperarEnter();
            break;
        case 3:
            showRoom(seat);
            esperarEnter();
            break;
        case 4:
            total(seat);
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
    printf("\n===========| CINEMA MENU |===========");
    printf("\n1 - Reserve seat");
    printf("\n2 - Free one seat");
    printf("\n3 - See the room");
    printf("\n4 - Total of free seats");
    printf("\n0 - Exit");
    printf("\nChoose an option:");
}

//Show seats
void showRoom(int seat[NL][NC]){
    printf("\n__________________________________");
    printf("\n|            MOVIE ROOM          |");
    printf("\n|                                |");
    printf("\n|     1  2   3  4   5  6   7  8  |");
    printf("\n|                                |");
    printf("\n|1#F  %d  %d X %d  %d   %d  %d X %d  %d  |", seat[0][0],seat[0][1],seat[0][2],seat[0][3],seat[0][4],seat[0][5],seat[0][6],seat[0][7]);
    printf("\n|2#E  %d  %d   %d  %d   %d  %d   %d  %d  |", seat[1][0],seat[1][1],seat[1][2],seat[1][3],seat[1][4],seat[1][5],seat[1][6],seat[1][7]);
    printf("\n|3#D  %d  %d   %d  %d   %d  %d   %d  %d  |", seat[2][0],seat[2][1],seat[2][2],seat[2][3],seat[2][4],seat[2][5],seat[2][6],seat[2][7]);
    printf("\n|4#C  %d  %d   %d  %d   %d  %d   %d  %d  |", seat[3][0],seat[3][1],seat[3][2],seat[3][3],seat[3][4],seat[3][5],seat[3][6],seat[3][7]);
    printf("\n|5#B  %d  %d   %d  %d   %d  %d   %d  %d  |", seat[4][0],seat[4][1],seat[4][2],seat[4][3],seat[4][4],seat[4][5],seat[4][6],seat[4][7]);
    printf("\n|6#A  %d  %d   %d  %d   %d  %d   %d  %d  |", seat[5][0],seat[5][1],seat[5][2],seat[5][3],seat[5][4],seat[5][5],seat[5][6],seat[5][7]);
    printf("\n|                                |");
    printf("\n|              SCREEN            |");
    printf("\n|                                |");
    printf("\n|Free = 0                        |");
    printf("\n|Ocuppied = 1                    |");
    printf("\n|________________________________|");
}

//Reserve seat
void reserveSeat(int seat[NL][NC]){
    int seatLine;
    int seatColumn;
    printf("\nSelect your seat");
    printf("\nLine(Number):");
    scanf("%d",&seatLine);
    printf("\nColumn:");
    scanf("%d",&seatColumn);
    if (seatLine>=1 && seatLine <=6 && seatColumn>=1 && seatColumn <=8){
        seatLine--;
        seatColumn--;
        if (seat[seatLine][seatColumn] == 0){
            seat[seatLine][seatColumn] = 1;
            printf("\nSeat selected!");
        }
        else{
            printf("\nThis seat is already occupied!");
        }
    }
    else{
        printf("\nPlease select a valid position.");
    }
}

//Free seat
void freeSeat(int seat[NL][NC]){
    int seatLine;
    int seatColumn;
    printf("\nSelect the seat you want to free up");
    printf("\nLine(Number):");
    scanf("%d",&seatLine);
    printf("\nColumn:");
    scanf("%d",&seatColumn);
    if (seatLine>=1 && seatLine <=6 && seatColumn>=1 && seatColumn <=8){
        seatLine--;
        seatColumn--;
        if (seat[seatLine][seatColumn] == 1){
            seat[seatLine][seatColumn] = 0;
            printf("\nThs seat is free now!");
        }
        else{
            printf("\nThis seat is not taken!");
        }
    }
    else{
        printf("\nPlease select a valid position.");
    }
}

//Total free seats
void total(int seat[NL][NC]){
    int total;
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            if (seat[i][j] ==  0){
                total++;
            }
        }
    }
    printf("\nThe total amount of free seats is: %d",total);
}