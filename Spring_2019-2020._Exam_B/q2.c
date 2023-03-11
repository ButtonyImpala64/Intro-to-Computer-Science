#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int LongestSequence (int a[], int n, int k);

int main() {
    
    int n = 12;
    int a[] = {1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0};
    int k = 3;

    printf("%d", LongestSequence(a, n, k));

    return 0;
}

int LongestSequence (int a[], int n, int k) {
    int longest = 0, zero_num = 0, current = 0;

    int *in_between = malloc(n*sizeof(int));

    for (int i = 0, current = 0, last = -1; i < n; i++) {
        if (a[i] == 0) {
            in_between[current] = i - last - 1;
            current++;
            last = i;
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d\n", in_between[i]);
    }

    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] == 0) {
            zero_num++;
        }

        if (zero_num > k) {
            if (current > longest) longest = current;

            current -= (in_between[j]);
            j++;

            zero_num--;

        } else {
            current++;
        }

    }

    free(in_between);

    return longest;

}