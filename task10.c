#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 6

char *concatenations(const char *a, const char *b) {
    char *s = (char *) calloc(100, sizeof(char));
    strcat(s, a);
    strcat(s, b);
    return s;
}

int main() {
    setlocale(LC_ALL, "");
    char **dictionary;
    int f = 0;

    dictionary = (char **) malloc(N * sizeof(char *));
    printf("Введите словарь из %d слов:\n", N);
    for (int i = 0; i < N; i++) {
        dictionary[i] = (char *) malloc(50 * sizeof(char));
        fgets(dictionary[i], 50, stdin);
        // Удаление символа новой строки, если он есть
        size_t len = strlen(dictionary[i]);
        if (len > 0 && dictionary[i][len - 1] == '\n') {
            dictionary[i][len - 1] = '\0';
        }
    }

    printf("\nСписок слов, полученных с помощью конкатенации слов словаря:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < N; z++) {
                char *concatenated = concatenations(dictionary[i], dictionary[j]);
                if (strcmp(concatenated, dictionary[z]) == 0) {
                    printf("%s + %s = %s\n", dictionary[i], dictionary[j], dictionary[z]);
                    f = 1;
                }
                free(concatenated);
            }
        }
    }

    if (f == 0) {
        printf("Нет таких слов\n");
    }

    for (int i = 0; i < N; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}
