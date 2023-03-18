#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6

int longest_path(int roads[N][N], int src, int dest);
void longest_path_aux(int roads[N][N], int src, int dest, int cities[], int *maxp, int cur);
bool Possible(int roads[N][N], int src, int next, int cities[]);

int main() {

    int roads[N][N] = {{0, 1, 0, 0, 0, 0},
                    {1, 0, 1, 0, 0, 0}, 
                    {0, 1, 0, 1, 1, 1},
                    {0, 0, 1, 0, 1, 0},
                    {0, 0, 1, 1, 0, 1},
                    {0, 0, 1, 0, 1, 0}};

    printf("%d\n", longest_path(roads, 0, 5));

    return 0;
}

int longest_path(int roads[N][N], int src, int dest) {

    int cities[N]; //to check if the city is available(not passed by twice).
    int max = -1;

    for (int i = 0; i < N; i++) {
        cities[i] = 1;
    }

    cities[src] = 0;
    longest_path_aux(roads, src, dest, cities, &max, 0);

    return max;

}

void longest_path_aux(int roads[N][N], int src, int dest, int cities[], int *maxp, int cur) {

    if (src == dest)
        if (cur > *maxp)
            *maxp = cur;

    for (int next = 0; next < N; next++) {
        if (!Possible(roads, src, next, cities)) continue;
        cities[next] = 0;
        longest_path_aux(roads, next, dest, cities, maxp, cur+1);
        cities[next] = 1;
    }

    return;

}

bool Possible(int roads[N][N], int src, int next, int cities[]) {

    if (cities[next] == 0)
        return false;
    else if (roads[src][next] == 0)
        return false;

    return true;

}