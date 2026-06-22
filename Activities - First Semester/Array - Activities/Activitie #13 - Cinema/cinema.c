#include <stdio.h>
#include <windows.h>

//Variável global modificavel
#define NL 6
#define NC 8

//Prototypes
void esperarEnter();
void printMenu();

int main(){
    SetConsoleOutputCP(65001);
    int array[NL][NC], option = -1;

    do
    {
        void printMenu();
        scanf("%d",&option);
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
    printf("\n1 - Reservar assento",
           "\n2 - Liber aasdasdaar assento",
           "\n3 - Mostrar sala",
           "\n4 - Total de lugares livres",
           "\n0 - Sair",
           "\nChoose an option:"
    );
}