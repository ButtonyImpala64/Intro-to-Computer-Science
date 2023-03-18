#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3

int FindMinimumNumDressColors(int color_map[N][N]);
void FindMinimumNumDressColorsAux(int color_map[N][N], int colors[N], int n, int cur, int *minp, bool *possiblep);
int ColorAvailable(int color_map[N][N], int colors[N], int n, int color);

int main() {

    int color_map[N][N] = {{0, 0, 0}, {0, 0, -1}, {0, 0, 0}};

    printf("%d\n", FindMinimumNumDressColors(color_map));


    return 0;
}

int FindMinimumNumDressColors(int color_map[N][N]) {

    int colors[N];
    int min = 5;
    bool possible = 0;

    for (int i = 0; i < N; i++)
        colors[i] = -1;
        
    FindMinimumNumDressColorsAux(color_map, colors, N, 0, &min, &possible);

    if (!possible) return -1;

    return min;

}

void FindMinimumNumDressColorsAux(int color_map[N][N], int colors[N], int n, int cur, int *minp, bool *possiblep) {

    if (n == 0) {
        *possiblep = true;
        if (cur < *minp)
            *minp = cur;
        return;
    }


    for (int i = 0; i < N; i++) {
        if (!ColorAvailable(color_map, colors, n, i)) continue;
        colors[n-1] = i;
        if (i+1 > cur)
            FindMinimumNumDressColorsAux(color_map, colors, n-1, i+1, minp, possiblep);
        else
            FindMinimumNumDressColorsAux(color_map, colors, n-1, cur, minp, possiblep);
        colors[n-1] = -1;
    }


}

int ColorAvailable(int color_map[N][N], int colors[N], int n, int color) {
    
    for (int i = N-1; i > n-1; i--) {

        if (color_map[n-1][i] == -1 && colors[i] == color) return 0;
        if (color_map[n-1][i] == 1 && colors[i] != color) return 0;

        if (color_map[i][n-1] == -1 && colors[i] == color) return 0;
        if (color_map[i][n-1] == 1 && colors[i] != color) return 0;

    }

    
    return 1;
}

