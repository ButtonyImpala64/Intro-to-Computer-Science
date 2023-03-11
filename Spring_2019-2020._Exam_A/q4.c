#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool IsKSplittable(int arr[], int n, int k);
bool IsKSplittable_aux(int arr[], int n, int k, int index, int used[], int sum[]);

int main() {

    int arr[] = {9, -2, 3, 17, 5, 3, 8, 4, 1, 1, 2};
    int n = 11;

    printf("%d\n", IsKSplittable(arr, n, 4));

    return 0;
}

bool IsKSplittable(int arr[], int n, int k) {
    int *used = malloc(k*sizeof(int));
    int *sums = malloc(k*sizeof(int));

    for (int i = 0; i < k; i++) {
        used[i] = 0;
        sums[i] = 0;
    }

    bool res = IsKSplittable_aux(arr, n, k, 0, used, sums);

    free(used);
    free(sums);

    return res;
}

bool IsKSplittable_aux(int arr[], int n, int k, int index, int used[], int sums[]) {
    if (index == n) {
        int comp = sums[0];
        for (int i = 1; i < k; i++)
            if (sums[i] != comp || !used[i])
                return false;

        printf("%d\n", sums[0]);

        return true;
    }
    
    for (int i = 0; i < k; i++) {
        sums[i] += arr[index];
        used[i]++;
        if (IsKSplittable_aux(arr, n, k, index+1, used, sums))
            return true;
        sums[i] -= arr[index];
        used[i]--;
    }

    return false;

}