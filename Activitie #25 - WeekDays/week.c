#include <stdio.h>
#include <Windows.h>

char *nomeDia;

char* nomeDoDia(int dia){
    switch (dia)
    {
    case 1:
        return "Segunda";
    
    case 2:
        return "Terça";
    case 3:
        return "Quarta";
    case 4:
        return "Quinta";
    case 5:
        return "Sexta";
    case 6:
        return "Sábado";
    case 7:
        return "Domingo";
    
    default:
        printf("Erro no programa");
        break;
    }
}
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(){
    SetConsoleOutputCP(65001);
    for (int i = 1; i <= 7; i++)
    {
        printf("\nDia %d: %s",i,nomeDoDia(i));
    }
    esperarEnter();
}