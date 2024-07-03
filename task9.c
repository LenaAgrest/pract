#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функция для вычисления индекса в упакованной верхнетреугольной матрице
int index(int i, int j, int n) {
    return i * n - (i - 1) * i / 2 + (j - i);
}

// Функция для умножения двух верхнетреугольных матриц
void multiply_upper_triangular(int *a, int *b, int *c, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            c[index(i, j, n)] = 0;
            for (int k = i; k <= j; ++k) {
                c[index(i, j, n)] += a[index(i, k, n)] * b[index(k, j, n)];
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;

    printf("Введите размер матриц: ");
    scanf("%d", &n);

    int size = n * (n + 1) / 2;
    int *a = (int *)malloc(size * sizeof(int));
    int *b = (int *)malloc(size * sizeof(int));
    int *c = (int *)malloc(size * sizeof(int));

    if (a == NULL || b == NULL || c == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите элементы первой верхнетреугольной матрицы в упакованном виде:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &a[i]);
    }

    printf("Введите элементы второй верхнетреугольной матрицы в упакованном виде:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &b[i]);
    }

    multiply_upper_triangular(a, b, c, n);

    printf("Результирующая матрица в упакованном виде:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");

    free(a);
    free(b);
    free(c);

    return 0;
}
