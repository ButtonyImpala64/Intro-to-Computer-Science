#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int findPartiallySorted(int* arr, int n, int x);
int search_neighbors(int arr[], int index, int x);

int main() {

    int arr[] = {2, 4, 11, 7, 12, 17, 41, 37, 32, 55, 64};

    printf("%d\n", findPartiallySorted(arr, 11, 11));


    return 0;
}

int findPartiallySorted(int* arr, int n, int x) {

    int l = 0, r = n-1, res, mid;

    while (l <= r) {
        mid = (l+r)/2;
        if (arr[mid] == x) return mid;

        if ((res = search_neighbors(arr, mid, x)) != -1)
            return res;

        if (arr[mid] < x)
            l = mid+1;
        else
            r = mid-1;

    }

    return -1;

}

int search_neighbors(int arr[], int index, int x) {

    for (int i = 1; ; i++) {
        if (arr[index+i] == x)
            return i+index;
        if (arr[index+i] > arr[index])
            break;
    }

    for (int i = 1; ; i++) {
        if (arr[index-i] == x)
            return index-i;
        if (arr[index] > arr[index-i])
            break;
    }

    return -1;

}