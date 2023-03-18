#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 2

void findSubArray(int* cumsum, int n, int sum, int indices[N]);
int arr_val(int cumsum[], int index);

int main() {

    int cumsum[] = {1, 1, 5, 7, 9};
    int indices[N] = {1, 1};

    findSubArray(cumsum, 6, 6, indices);

    printf("%d %d\n", indices[0], indices[1]);

    return 0;
}

void findSubArray(int* cumsum, int n, int sum, int indices[N]) {

    int tail = 0, sum2 = 0;
        

    for (int i = 0; i < n; i++) {
        sum2 += arr_val(cumsum, i);
        if (sum2 == sum && tail != i) {
            indices[0] = tail;
            indices[1] = i;
        } else if (sum2 > sum) {
            while(sum2 > sum && tail < i) {
                sum2 -= arr_val(cumsum, tail);
                tail++;
            }
            if (sum2 == sum && tail != i) {
                indices[0] = tail;
                indices[1] = i;
            }
        }
    }

}

int arr_val(int cumsum[], int index) {

    if (index == 0)
        return cumsum[0];
    else
        return cumsum[index]-cumsum[index-1];

}