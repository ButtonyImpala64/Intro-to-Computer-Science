#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int count_occurences(int arr[], int n, int x);
int ceil_search(int arr[], int n, int x);
int floor_search(int arr[], int n, int x);

int main() {

    int arr[] = {-5, 0, 1, 1, 3, 3, 4, 4, 4, 7, 13, 42};
    int n = 12, x = 3;

    printf("%d\n", count_occurences(arr, n, x));


    return 0;
}

int count_occurences(int arr[], int n, int x) {
    int ceil = ceil_search(arr, n, x);
    int floor = floor_search(arr, n, x);

    if (ceil == -1) return 0;

    return ceil - floor + 1;


 }


int ceil_search(int arr[], int n, int x) {

    int l = 0, r = n-1, mid;

    while (l <= r) {
        mid = (l+r)/2;

        if (arr[mid] == x) {

            if (mid == n-1) return mid;
            if (arr[mid+1] > x) return mid;

        } 

        if (arr[mid] < x || arr[mid] == x) {
            l =  mid+1;
        }

        if (arr[mid] > x) {
            r = mid-1;
        }


    }

    return -1;

}

int floor_search(int arr[], int n, int x) {

    int l = 0, r = n-1, mid;

    while (l <= r) {
        mid = (l+r)/2;

        if (arr[mid] == x) {

            if (mid == 0) return mid;
            if (arr[mid-1] < x) return mid;

        } 

        if (arr[mid] < x) {
            l =  mid+1;
        }

        if (arr[mid] > x || arr[mid] == x) {
            r = mid-1;
        }


    }

    return -1;

}

