#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функция для удаления нулевых элементов из массива
void remove_zeros(int *A, int n, int *new_size) {
    int j = 0; // Индекс для нового массива
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) {
            A[j++] = A[i];
        }
    }
    *new_size = j; // Новый размер массива без нулей
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int new_size;
    remove_zeros(A, n, &new_size);
    
    printf("Массив без нулей:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    free(A); // Освобождение выделенной памяти
    return 0;
}
