#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int CalculateWaterVolume(int heights[], int n);
void get_help(int heights[], int n, int help[]);
int min(int a, int b);

int main() {

    int heights[] = {2, 1, 1, 4, 1, 1, 2, 3};
    int n = 8;


    printf("%d\n", CalculateWaterVolume(heights, n));
    


    return 0;
}

int CalculateWaterVolume(int heights[], int n) {

    int *help = malloc(n*sizeof(int)), counter = 0;

    get_help(heights, n, help);

    for (int i = 1; i < n-1; i++) {
        counter += help[i]-heights[i];
    }

    free(help);

    return counter;
}

void get_help(int heights[], int n, int help[]) {

    int max = 0;

    int *left = malloc(n*sizeof(int));
    int *right = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {

        if (heights[i] > max) max = heights[i];
        left[i] = max;

    }

    max = 0;

    for (int i = n-1; i > 0; i--) {

        if (heights[i] > max) max = heights[i];
        right[i] = max;

    }

    for (int i = 0; i < n; i++) {

        help[i] = min(left[i], right[i]);

    }

    free(left);
    free(right);

}

int min(int a, int b) {
    return a>b ? b : a;
}