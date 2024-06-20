#include <stdio.h>
#include <windows.h>

// Структура для представления точки на плоскости
typedef struct {
    float x;
    float y;
} Point;

// Функция для вычисления векторного произведения
float cross_product(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Point A, B, C;

    // Ввод координат вершин треугольника
    printf("Введите координаты вершины A (x y): ");
    scanf("%f %f", &A.x, &A.y);

    printf("Введите координаты вершины B (x y): ");
    scanf("%f %f", &B.x, &B.y);

    printf("Введите координаты вершины C (x y): ");
    scanf("%f %f", &C.x, &C.y);

    // Вычисляем векторное произведение
    float cross_prod = cross_product(A, B, C);

    // Определяем порядок обхода и выводим результат
    printf("Вершины треугольника в порядке обхода по часовой стрелке: ");
    if (cross_prod < 0) {
        printf("A (%.2f, %.2f), C (%.2f, %.2f), B (%.2f, %.2f)\n", A.x, A.y, C.x, C.y, B.x, B.y);
    } else {
        printf("A (%.2f, %.2f), B (%.2f, %.2f), C (%.2f, %.2f)\n", A.x, A.y, B.x, B.y, C.x, C.y);
    }

    return 0;
}
