#include <stdio.h>
#include <windows.h>
void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(void){
    SetConsoleOutputCP(65001);
    float base, altura, area;

    printf("Digite o tamanho da base em metros: ");
    scanf("%f",&base);
    printf("Digite a altura em metros: ");
    scanf("%f",&altura);
    area = base*altura;
    if (area >= 0 & area <150){
     printf("Sua área é pequena, seu tamanho é %.0fm². ",area);
    }
    else if (area >= 150 & area <=350){
     printf("Sua área é média, seu tamanho é %.0fm². ",area);
    }
    else if (area > 350){
     printf("Sua área é grande, seu tamanho é %.0fm². ",area);
    }
    else{
        printf("Valor da sua área ficou menor que 0, digite valores válidos.");
    }
    esperarEnter();

}