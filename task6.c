#include <stdio.h>
#include <windows.h>

// Функция для поиска индекса k
int find_interval(int *M, int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid < n - 1 && M[mid] <= x && x <= M[mid + 1]) {
            return mid;
        } else if (x < M[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // Если интервал не найден
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n, x;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int M[n];
    printf("Введите элементы массива (отсортированные):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &M[i]);
    }

    printf("Введите значение x: ");
    scanf("%d", &x);

    int k = find_interval(M, n, x);
    if (k != -1) {
        printf("Индекс k: %d (M[%d] = %d, M[%d] = %d)\n", k, k, M[k], k + 1, M[k + 1]);
    } else {
        printf("Такого интервала нет.\n");
    }

    return 0;
}
