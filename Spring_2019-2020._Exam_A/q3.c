#include <stdlib.h>
#include <stdio.h>

void reverse_words(char *str);
void reverse_string(char *str, int n);
void reverse_words_aux(char *str, int n);


int main() {

    char *str = "geeks quiz practice code";
    int n = 0;

    

    while(str[n])
        n++;

    printf("%d", n);

    reverse_words(str);
    for (int i = 0; i < n; i++)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}

void reverse_words(char *str) {

    int n = 0;

    while(str[n])
        n++;

    reverse_string(str, n);

    //reverse_words_aux(str, n);

}

void reverse_string(char *str, int n) {
    char temp;
    /*for (int i = 0; i < (n-1)/2; i++) {
        temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }*/

    int a = 0, b = n-1;

    while (a <= b) {
        temp = str[a];
        *(str+a) = *(str+b);
        //str[b] = temp;
        a++;
        b--;
    }

}

void reverse_words_aux(char *str, int n) {
    int a, b;
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ' && str[i+1] != ' ') {
            a = i;
        }
        if (str[i] != ' ' && str[i+1] == ' ') {
            b = i;
            reverse_string(str+a, b-a-1);
        }
    }
}