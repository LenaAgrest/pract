#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k, l;
    printf("Введите два числа: ");
    scanf("%d %d", &k, &l);

    // Переменная для хранения итогового результата
    int result = 0;

    // Массив для хранения промежуточных произведений
    int intermediate_results[10];
    int num_intermediate_results = 0;

    int temp_l = l;
    int shift = 0;

    // Вычисление промежуточных произведений
    while (temp_l > 0) {
        int digit = temp_l % 10;
        int intermediate_result = k * digit;
        intermediate_results[num_intermediate_results++] = intermediate_result;
        result += intermediate_result * pow(10, shift);
        temp_l /= 10;
        shift++;
    }

    // Вывод промежуточных произведений и итогового результата
    printf("%d\n", k);
    printf("x %d\n", l);
    printf("-----\n");

    printf("%d\n", result);

    return 0;
}
