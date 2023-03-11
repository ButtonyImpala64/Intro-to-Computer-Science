#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Scramble(char *cubes[], int n, int colors[], char* target);
bool Scramble_Aux(char *cubes[], int n, int colors[], char* target, int tn, int curr, int* used_cubes, int* used_colors);



int main() {

    char *cubes[] = {"ABC", "AEI", "EOU", "LNRST"};
    int n = 4;
    int colors[4] = {0, 0, 1, 2};
    char *target = "";

    if (Scramble(cubes, n, colors, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

bool Scramble(char *cubes[], int n, int colors[], char* target) {

    int tn = 0;
    while (target[tn])
        tn++;

    int *used_colors = malloc(n*sizeof(int));
    int *used_cubes = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        used_colors[i] = false;
        used_cubes[i] = false;
    }

    return Scramble_Aux(cubes, n, colors, target, tn, 0, used_cubes, used_colors);

}

bool Scramble_Aux(char *cubes[], int n, int colors[], char* target, int tn, int curr, int* used_cubes, int* used_colors) {
    if (curr == tn)
        return true;

    for (int i = 0; i < n; i++) {
        if (!used_cubes[i] && !used_colors[i]) {

            int length = 0;

            while (cubes[i][length]) {
                //printf("%c", cubes[i][length]);
                length++;
            }

            //printf("\n\n");

            for (int j = 0; j < length; j++) {
                if (cubes[i][j] == target[curr]) {
                    used_cubes[i]++;
                    used_colors[i]++;
                    if (Scramble_Aux(cubes, n, colors, target, tn, curr+1, used_cubes, used_colors)) return true;
                    used_cubes[i]--;
                    used_colors[i]--;
                }
            }

        }
    }

    return false;

}
