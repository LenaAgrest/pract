#include <stdio.h>
#include <math.h>
#include <windows.h>

// Функция для вычисления длины стороны треугольника
float calculate_side(float height) {
    return sqrt(2 * height * height);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    float height, side;

    // Вводим высоту треугольника
    printf("Введите высоту треугольника: ");
    scanf("%f", &height);

    // Вычисляем длину стороны равнобедренного треугольника
    side = calculate_side(height);

    // Выводим результат
    printf("Длина стороны треугольника: %.2f\n", side);

    return 0;
}
