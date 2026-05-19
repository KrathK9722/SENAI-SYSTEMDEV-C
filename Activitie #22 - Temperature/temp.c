#include <stdio.h>
#include <Windows.h>

//Variaveis
float celsius, fahrenheit, kelvin;

float celsiusParaFahrenheit(float celsius){
    return (celsius*9/5)+32;
}

float celsiusParaKelvin(float celsius){
    return celsius + 273.15;
}

int main(){
    SetConsoleOutputCP(65001);
    printf("Digite a temperatura em Celsius: ");
    scanf("%f",&celsius);

    fahrenheit = celsiusParaFahrenheit(celsius);
    kelvin = celsiusParaKelvin(celsius);

    printf("%.1f°C → %.1f°F → %.2f K",celsius,fahrenheit,kelvin);
}
