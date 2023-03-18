#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char annoying(char* str);
void unAnnoy(char *arr[], int n);
int get_length(char *str);

int main() {

    char *str = "";
    char *arr[] = {"hakuna matata", "nnnanana$$", ""};

    unAnnoy(arr, 3);

    for (int i = 0; i < 3; i++) {
        printf("%s\n", arr[i]);
    }


    return 0;
}

char annoying(char* str) {

    int n = 0;

    while (str[n])
        n++;

    if (n == 0)
        return 0;

    int hist[127] = {0};

    for (int i = 0; i < n; i++) {
        hist[str[i]-1]++;
    }

    int max = 0, ch = 0;

    for (int i = 0; i < 127; i++) {
        if (hist[i] >= max) {
            ch = i+1;
            max = hist[i];
        }
    }

    printf("%c ", ch);

    return ch;


}

void unAnnoy(char *arr[], int n) {

    int m;
    char an;

    for (int i = 0; i < n; i++) {
        m = 0;

        while (arr[i][m])
            m++;

        if (m == 0) continue;

        an = annoying(arr[i]);

        for (int j = 0; j < m; j++) {
            if (arr[i][j] == an)
                arr[i][j] = 128;
        }

        for (int j = 0, index = -1; j < m; j++) {
            if (arr[i][j] == 128 && index == -1) {
                index = j;
            } else {
                if (index != -1) {
                    arr[i][index] = arr[i][j];
                    arr[i][j] = 128;
                    index++;
                }
            }
        }

        
    }

}

int get_length(char *str) {
    int n = 0;

    while (str[n])
        n++;

    return n;
}