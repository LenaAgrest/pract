#include <iostream>
#include <cstring>
#include <cstdlib>

#define N 6

using namespace std;

char *concatenate(char *a, char *b) {
    char *s = (char *)calloc(100, sizeof(char));
    strcat(s, a);
    return strcat(s, b);
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char **dictionary;
    int f = 0;
    dictionary = (char **)malloc(N * sizeof(char *));
    cout << "Введите словарь из " << N << " слов" << endl;
    for (int i = 0; i < N; i++) {
        dictionary[i] = (char *)malloc(50 * sizeof(char));
        cin.getline(dictionary[i], 50);
    }

    cout << endl << "Список слов, полученных с помощью конкатенации слов словаря: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < N; z++) {
                if (strcmp(concatenate(dictionary[i], dictionary[j]), dictionary[z]) == 0) {
                    cout << dictionary[i] << " + " << dictionary[j] << " = " << dictionary[z] << endl;
                    f = 1;
                }
            }
        }
    }

    if (f == 0) {
        cout << "нет таких слов" << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}
