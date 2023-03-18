#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int FindDuplicate(int a[], int n);

int main() {

    int a[] = {1, 2, 3, 3, 4, 5};

    printf("%d\n", FindDuplicate(a, 6));

    return 0;
}

int FindDuplicate(int a[], int n) {

    int cur = 0, temp;
    while (true) {
        if (a[cur] == cur+1) {
            cur++;
        } else {
            if (a[cur] == a[a[cur]-1]) return a[cur];
            temp = a[cur];
            a[cur] = a[a[cur]-1];
            a[a[cur]-1] = temp;
        }
    }

    return -1;

}