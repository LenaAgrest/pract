#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

// Функция для вычисления e с помощью ряда
double compute_e_series(int iterations) {
    double e = 2.0;
    double factorial = 1.0;
    
    for (int n = 2; n <= iterations; ++n) {
        factorial *= n;
        e += 1.0 / factorial;
    }
    
    return e;
}

// Функция для вычисления e с помощью бесконечной дроби
double compute_e_fraction(int iterations) {
    double e = 1.0;
    
    for (int n = iterations; n > 0; --n) {
        e = 1.0 + 1.0 / n * e;
    }
    
    return e;
}

int main() {
 
    SetConsoleOutputCP(CP_UTF8);
    int max_iterations; 
    printf("Введите количество итераций: ");
    scanf("%d", &max_iterations);
  // Максимальное количество итераций для оценки скорости сходимости
    
    printf("Сравнение скорости сходимости для вычисления числа e\n\n");
    printf("Точность\t\tРяд\t\t\tБесконечная дробь\n");
    printf("------------------------------------------------\n");
    
    for (int precision = 1; precision <= max_iterations; ++precision) {
        int iterations = pow(10, precision);
        
        // Вычисление e с помощью ряда
        clock_t start_time_series = clock();
        double e_series = compute_e_series(iterations);
        clock_t end_time_series = clock();
        double series_time = (double)(end_time_series - start_time_series) / CLOCKS_PER_SEC;
        
        // Вычисление e с помощью бесконечной дроби
        clock_t start_time_fraction = clock();
        double e_fraction = compute_e_fraction(iterations);
        clock_t end_time_fraction = clock();
        double fraction_time = (double)(end_time_fraction - start_time_fraction) / CLOCKS_PER_SEC;
        
        printf("10^%d\t\t%.10f (%.6f s)\t%.10f (%.6f s)\n", precision, e_series, series_time, e_fraction, fraction_time);
    }
    
    return 0;
}
