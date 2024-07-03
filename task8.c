#include <stdio.h>
#include <windows.h>

// Функция для вычисления симметричных точек
void find_symmetric_points(double *x, double *y, double a, double b, double c, int n) {
    double denominator = a * a + b * b;
    for (int i = 0; i < n; i++) {
        double d = (a * x[i] + b * y[i] + c) * 2.0;
        x[i] = x[i] - a * d / denominator;
        y[i] = y[i] - b * d / denominator;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    double a, b, c;

    printf("Введите коэффициенты прямой (a, b, c) для уравнения ax + by + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("Введите количество точек: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Введите координаты точек (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    find_symmetric_points(x, y, a, b, c, n);

    printf("Симметричные точки:\n");
    for (int i = 0; i < n; i++) {
        printf("(%.2lf, %.2lf)\n", x[i], y[i]);
    }

    return 0;
}
