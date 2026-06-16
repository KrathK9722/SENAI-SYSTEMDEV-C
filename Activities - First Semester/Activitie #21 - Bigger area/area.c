#include <stdio.h>
#include <Windows.h>

//Variaveis
float base, altura, area[2];

float areaTriangulo(float base, float altura){
    return (base*altura)/2;
}
float areaRetangulo(float base, float altura){
    return base*altura;
}
void esperarEnter()
{
    while (getchar() != '\n'); 
    printf("\nPressione ENTER para continuar...");
    getchar();
}
int main(){
    SetConsoleOutputCP(65001);
    printf("Digite a base em metros: ");
    scanf("%f",&base);
    printf("Digite a altura em metros: ");
    scanf("%f",&altura);

    area[0] = areaRetangulo(base,altura);
    area[1] = areaTriangulo(base,altura);

    if (area[0] > area[1]){
        printf("O retangulo tem uma área maior com %.1fm2, enquanto o triangulo tem somente %.1fm2.",area[0],area[1]);
    }
    else if (area[0] = area[1]){
        printf("O retangulo e o triangulo tem uma área igual de %.1fm2.",area[0]);
    }
    esperarEnter();
    //Impossivel área do triangulo ficar maior que a área do retangulo.
    
}
