#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5

int find_num_partitions(int A[N][N]);
int find_num_partitions_aux(int A[N][N], int used[], int p[], int cur);
bool Possible(int A[][N], int used[], int p[], int cur, int num);

int main() {

    int A[N][N] = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 0, 0, 1}};

    printf("%d\n", find_num_partitions(A));
    
    return 0;
}

int find_num_partitions(int A[N][N]) {

    int p[N/2];
    for (int i = 0; i < N/2; i++)
        p[i] = -1;

    int used[N] = {0};

    return find_num_partitions_aux(A, used, p, 0);

}

int find_num_partitions_aux(int A[N][N], int used[], int p[], int cur) {

    if (cur == N/2) return 0;

    int counter = 0;

    for (int num = 0; num < N; num++) {
        if (used[num] == 1) continue;
        p[cur] = num;
        used[num] = 1;
        if (Possible(A, used, p, cur, num)) counter++;
        counter += find_num_partitions_aux(A, used, p, cur+1);
        p[cur] = -1;
        used[num] = 0;
    }

    return counter;

}

bool Possible(int A[][N], int used[], int p[], int cur, int num) {

    

    if (cur != 0 && p[cur-1] < p[cur]) return false;

    for (int i = 0; i < N; i++) {
        if (used[i] == 1) {
            if (A[num][i] == 0) return false;
        } else {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 0 && used[j] == 0) return false;
            }
        }
    }

    return true;

}