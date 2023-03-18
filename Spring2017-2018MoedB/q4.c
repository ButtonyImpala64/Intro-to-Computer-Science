#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool Proportionalable(int arr[], int n);
bool ProportionalableAux(int arr[], int n, int twice[], int cur);
bool Possible(int arr[], int num, int *twice, int cur, int n);

int main() {

    int arr[6];

    if (Proportionalable(arr, 3)) {
        printf("true\n");
        for (int i = 0; i < 6; i++)
            printf("%d ", arr[i]);
    } else
        printf("false\n");

    return 0;
}


bool Proportionalable(int arr[], int n) {

    int *twice = malloc(n*sizeof(int));
    if (twice == NULL) {
        printf("Memory Allocation Failure");
    }

    for (int i = 0; i < n; i++) {
        twice[i] = 0;
    }

    return ProportionalableAux(arr, n, twice, 0);

    free(twice);

}

bool ProportionalableAux(int arr[], int n, int *twice, int cur) {

    if (cur == 2*n) {
        return true;
    }

    for (int num = 1; num < n+1; num++) {
        if (!Possible(arr, num, twice, cur, n)) continue;
        //printf("%d ", num);
        //printf("passes");
        twice[num-1]++;
        if (ProportionalableAux(arr, n, twice, cur+1)) return true;
        twice[num-1]--;
    }


    return false;

}

bool Possible(int arr[], int num, int *twice, int cur, int n) {
    if (twice[num-1] >= 2) return false;

    arr[cur] = num;


    for (int i = 0, false_counter = 0; i <= cur; i++) {

        if (i+arr[i]+1 <= cur) {
            if (arr[i+arr[i]+1] != arr[i]) {
                //printf("a");
                false_counter++;
            }
        }

        if (i-arr[i]-1 >= 0) {
            if (arr[i-arr[i]-1] != arr[i]) {
                //printf("b");
                false_counter++;
            }
        }


        if (false_counter >= 2)
            return false;

        if (2*n-1-(cur+1) < arr[cur] && arr[cur - arr[cur]-1] != arr[cur])
            return false;


    }

    return true;

}