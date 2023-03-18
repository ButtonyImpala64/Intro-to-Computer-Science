#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void stable_shuffle(int arr[], int n);
void switch_arrays(int a[], int b[], int n);

int main() {

    int arr[] = {7, 1, 8, 11, 4, 7, 3, 2};
    int n = 8;

    stable_shuffle(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);


    return 0;
}

void stable_shuffle(int arr[], int n) {

    if (n == 2) return;

    stable_shuffle(arr, n/2);
    stable_shuffle(arr+n/2, n/2);

    switch_arrays(arr+n/4, arr+n/2, n/4);

}

void switch_arrays(int a[], int b[], int n) {

    int temp;

    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }

}