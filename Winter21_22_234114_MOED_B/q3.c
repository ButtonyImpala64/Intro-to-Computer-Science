#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LETTERS_NUM 26

int get_safety(char* str);

int main() {

    printf("%d\n", get_safety("abc"));

    return 0;
}

int get_safety(char* str) {

    int letters[LETTERS_NUM][2];

    for (int i = 0; i < LETTERS_NUM; i++) {
        letters[i][0] = 0;
        letters[i][1] = -1;
    }

    int i;

    for (i = 0; str[i]; i++) {
        letters[str[i]-'a'][0]++;

        if (letters[str[i]-'a'][0] == 2)
            return i-letters[str[i]-'a'][1]-1;
        else
            letters[str[i]-'a'][1] = i;

    }
    
    return i-1;

}