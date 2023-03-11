#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int build_bridges(char roads[], int n, int bridges[]);
int build_bridges_aux(char roads[], int n, int bridges[], int guinea[], int cur, int* max, char* start);
void copy(int guinea[], int bridges[], int n);
int Max(int a, int b);

int main() {

    char *roads = "NNNNNN";
    int n = 6;
    int bridges[6] = {-1};

    printf("%d\n", build_bridges(roads, n, bridges));

    for (int i = 0; i < n; i++) {
        printf("%d ", bridges[i]);
    }


    return 0;
}

int build_bridges(char roads[], int n, int bridges[]) {

    //int max = -1, cur = -1;
    int max = 0;
    int *maxp = &max;
    int guinea[6] = {-1};
    //int used[] = {0};


    build_bridges_aux(roads, n, bridges, guinea, 0, maxp, roads);

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

int build_bridges_aux(char roads[], int n, int bridges[], int guinea[], int cur, int *maxp, char* start) {
    if (n <= 1) {
        if (n == 1) {
            guinea[0] = -1;
        }
    //    if (cur > max) {
      //      max = cur;
        //    copy(guinea, bridges, n);
        //}

        return 0;
    }

    int index = 0;
    int local_max = 0, counter = 0;

    for (int i = 0, inmax = 0; i < n; i++, inmax = 0) {

        if (roads[i] == roads[0]) {
            if (i != 0 && counter == 0) {
                counter++;
                cur++;
            }
            inmax += build_bridges_aux(roads+1, i-1, bridges+1, guinea+1, cur, maxp, start);
            if (roads+i+1 <= roads+n) {
                inmax += build_bridges_aux(roads+i+1, n-i-1, bridges+i+1, guinea+i+1, cur+inmax, maxp, start);
            }
        } else {
            continue;
        }

        if (i == 0) {
            if (inmax > local_max) {
                local_max = inmax;
                index = i;
                guinea[index] = -1;
            }
        } else {
            if (inmax+1 > local_max) {
                local_max = inmax+1;
                index = i;
                guinea[index] = guinea[0] = cur-1;
                counter++;
            }
            
        }

        

        
        

        //cur--;

    }

    if (counter == 1) cur--;
    printf("%d  %d\n\n", cur, local_max);



    if (cur+local_max > *maxp) {
        *maxp = cur+local_max-1;
        copy(guinea, bridges, n);
    }

    return local_max;

}

void copy(int guinea[], int bridges[], int n) {
    for (int i = 0; i < n; i++)
        bridges[i] = guinea[i];
}

int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
