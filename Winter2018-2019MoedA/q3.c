#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAILURE -1
#define SUCCESS 0

int merge_sort(int ar[], int n);
void merge(int a[], int n, int b[], int m, int c[]);


int main() {

    int arr[] = {3, 2, 1, 5, 7, 8, 2, 99};
    int n = 8;

    merge_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}


int merge_sort(int ar[], int n)
{
    int len, counter;
    int *temp_array, *base, *base2;
    
    temp_array = (int*) malloc(sizeof(int)*n);
    if (temp_array == NULL)
    {      
        printf("Dynamic Allocation Error in merge_sort");
        return FAILURE;
    }
    for (len = 1, counter = 0; len < n; len *= 2, counter++)
    {   

        if (counter % 2 == 0) {
            for (base = ar, base2 = temp_array; base < ar + n; base += 2 * len, base2 += 2 * len)
            {          
               merge(base, len, base + len, len, base2);
            }
        } else {
            for (base = temp_array, base2 = ar; base < temp_array + n; base += 2 * len, base2 += 2 * len)
            {          
                merge(base, len, base + len, len, base2);  
            }
        }

                  
    }

    //if (counter % 2 == 1)
        //memcpy(ar, temp_array, n);

    free(temp_array);
    return SUCCESS;
}

void merge(int a[], int n, int b[], int m, int c[]) {

    int ai = 0;
    int bi = 0;
    int ci = 0;

    while (ai < n && bi < m) {
        if (a[ai] < b[bi]) {
            c[ci] = a[ai];
            ai++;
        } else {
            c[ci] = b[bi];
            bi++;
        }
        ci++;
    }

    while(bi < m) {
        c[ci] = b[bi];
        bi++;
        ci++;
    }

    while(ai < n) {
        c[ci] = a[ai];
        ai++;
        ci++;
    }

}


