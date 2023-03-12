#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int build_bridges(char roads[], int n, int bridges[]);
int build_bridges_aux(char roads[], int n, int bridges[], int guinea[], int left_arr[], int cur, int if_left, int *maxp, char* start);
void copy(int a[], int b[], int n, int plus);
int Max(int a, int b);

int main() {

    char *roads = "NS";
    int n = 2;
    int *bridges = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        bridges[i] = -1;

    printf("%d\n", build_bridges(roads, n, bridges));

    for (int i = 0; i < n; i++) {
        printf("%d ", bridges[i]);
    }

    free(bridges);


    return 0;
}

int build_bridges(char roads[], int n, int bridges[]) {

    //int max = -1, cur = -1;
    int max = 0;
    int *maxp = &max;
    int *guinea = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        guinea[i] = -1;
    int *left_arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        left_arr[i] = -1;
    //int used[] = {0};




    build_bridges_aux(roads, n, bridges, guinea, left_arr, 0, 0, maxp, roads);

    free(guinea);
    free(left_arr);

    return max;

}

/*int build_bridges_aux(char roads[], int n, int bridges[], int guinea[], int cur, int max, char* start) {
    if (n <= 0) {
        //if (n == 1)
            //bridges[roads-start] = -1;
    //    if (cur > max) {
      //      max = cur;
        //    copy(guinea, bridges, n);
        //}
        return 0;
    }

    int index = 0;

    for (int i = 0, inmax = 0; i < n; i++, inmax = 0) {

        if (roads[i] == roads[0]) {
            inmax += build_bridges_aux(roads+1, i-1, bridges, guinea, 0, 0, start);
            if (roads+i+1 <= roads+n) {
                inmax += build_bridges_aux(roads+i+1, n-i-1, bridges, guinea, inmax, 0, start);
            }
        } else {
            continue;
        }

        if (i == 0) {
            if (inmax > max) {
                max = inmax;
                index = i;
                bridges[roads-start] = -1;
            }
        } else {
            if (inmax+1 > max) {
                max = inmax+1;
                index = i;
                bridges[roads-start+index] = bridges[roads-start] = max-1+cur;
            }
            
        }

        
        

        //cur--;

    }


    if (index != 0) bridges[roads-start+index] = bridges[roads-start] = max-1+cur;

    return max;

}*/

int build_bridges_aux(char roads[], int n, int bridges[], int guinea[], int left_arr[], int cur, int is_left, int *maxp, char* start) {
    if (n <= 1) {
        if (n == 1) {
            //guinea[0] = -1;
            if (is_left) {
                guinea[0] = -1;
                left_arr[0] = -1;
            }
            if (!is_left) {
                guinea[0] = -1;
                //copy(guinea, guinea, n, left);
                //bridges[0] = -1;
            }
        }
    //    if (cur > max) {
      //      max = cur;
        //    copy(guinea, bridges, n);
        //}

        return 0;

    }

    int index = 0, left = 0, pre_left = 0;
    int local_max = 0, counter = 0;

    for (int i = 0, inmax = 0; i < n; i++, inmax = 0) {

        if (roads[i] == roads[0]) {
            if (i != 0 && counter == 0) {
                counter++;
                cur++;
            }
            inmax += build_bridges_aux(roads+1, i-1, bridges+1, guinea+1, left_arr+1, cur, 1, maxp, start);
            pre_left = inmax;
            if (roads+i+1 <= roads+n) {
                inmax += build_bridges_aux(roads+i+1, n-i-1, bridges+i+1, guinea+i+1, left_arr+i+1, cur+inmax, 0, maxp, start);
            }
        } else {
            continue;
        }

        if (i == 0) {
            if (inmax >= local_max) {
                local_max = inmax;
                left = pre_left;
                index = i;
                guinea[index] = -1;
            }
        } else {
            if (inmax+1 >= local_max) {
                local_max = inmax+1;
                left = pre_left;
                index = i;
                guinea[index] = guinea[0] = cur-1;
                counter++;
            }
            
        }

        

        
        

        //cur--;

    }

    if (counter == 1) cur--;
    printf("%d  %d\n\n", cur, local_max);



    if (cur+local_max-1 >= *maxp && !is_left) {
        *maxp = cur+local_max-1;
        //copy(guinea, guinea, n, left);
        copy(left_arr+1, guinea+1, index-1, 0);
        copy(guinea, bridges, n, 0);
    }

    if (is_left) {
        //copy(guinea, guinea, n, left);
        copy(left_arr+1, guinea+1, index-1, 0);
        copy(guinea, left_arr, n, 0);
    }

    printf("\n\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", left_arr[i]);
    }
    printf("\n\n\n");

    return local_max;

}

void copy(int a[], int b[], int n, int plus) {
    if (n <= 0) return;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            b[i] = a[i]+plus;
        else
            b[i] = a[i];
    }
}

int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
