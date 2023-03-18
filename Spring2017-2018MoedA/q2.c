#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_high_factor_in_range(int n, int low, int high);

int main() {


    return 0;
}

void find_factors(int n, int *p, int *q) {

    int l = 1, r = n, mid;

    while (l <= r) {
        mid = (l+r)/2;

        if (n%mid == 0) break;

        if (is_high_factor_in_range(n, l, mid)) {
            r = mid-1;
        }

        if (is_high_factor_in_range(n, mid, r)) {
            l = mid+1;
        }
    }

    *q = mid;
    *p = n/mid;

    
}

//time comlexity = log^2(n)

