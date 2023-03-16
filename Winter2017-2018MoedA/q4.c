#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define M 2

bool SetTables(int vetoes[][M], int sitting[], int n, int all);
bool TableAvailable(int index, int table, int all, int sitting[], int vetoes[][M]);
void fill_with_minus_one(int sitting[]);
void PrintSitting(int sitting[]);

int main() {

    int sitting[42];
    int vetoes[][M] = { {3, 1}, {0, -1}, {-1, -1}, {2, -1}, {-1, 1} };
    int n = 5;

    fill_with_minus_one(sitting);

    if (SetTables(vetoes, sitting, n, n))
        printf("true\n");
    else
        printf("false");

    PrintSitting(sitting);


    return 0;
}

bool SetTables(int vetoes[][M], int sitting[], int n, int all) {

    if (n == 0) return true;

    for (int table = 0; table < 42; table++) {
        if (!TableAvailable(n-1, table, all, sitting, vetoes)) continue;
        sitting[n-1] = table;
        if (SetTables(vetoes, sitting, n-1, all)) return true;
        sitting[n-1] = -1;
    }

    return false;

}

bool TableAvailable(int index, int table, int all, int sitting[], int vetoes[][M]) {
    for (int i = 0; i < M; i++) {
        if (vetoes[index][i] != -1 && sitting[vetoes[index][i]] == table) return false;
    }

    for (int i = 0; i < all; i++) {
        if (sitting[i] == table) {
            for (int j = 0; j < M; j++) {
                if (vetoes[i][j] == index)
                    return false;
            }
        }
    }

    return true;
}

void fill_with_minus_one(int sitting[]) {
    for (int i = 0; i < 42; i++)
        sitting[i] = -1;
}

void PrintSitting(int sitting[]) {
    for (int i = 0; i < 42 && sitting[i] != -1; i++)
        printf("%d ", sitting[i]);
    printf("\n");
}