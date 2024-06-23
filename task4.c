#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int K[n][n];

    // Заполнение массива
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                K[i][j] = 0;
            } else {
                K[i][j] = 1;
            }
        }
    }

    // Вывод массива
    printf("Массив K(%d, %d):\n", n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", K[i][j]);
        }
        printf("\n");
    }

    return 0;
}
