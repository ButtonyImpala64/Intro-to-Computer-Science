#include <stdlib.h>
#include <stdio.h>

int FindFixedPoint (int a[], int n);

int main() {

    int a[] = {-3, 0, 1, 3, 4, 6, 13, 42};
    int n = 8;

    printf("%d\n", FindFixedPoint(a, n));

    return 0;
}


int FindFixedPoint (int a[], int n) {
    int l = 0, r = n-1, m;

    while (l <= r) {
        m = (l+r)/2;

        if (a[m] == m)
            return m;
        if (a[m] > m) {
            l = m+1;
            break;
        }
        if (a[m] < m) {
            r = m-1;
            break;
        }
    }

    return -1;
}
