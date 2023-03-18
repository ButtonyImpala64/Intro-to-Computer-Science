#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char find_first_unique(char *str);

int main() {

    printf("%c", find_first_unique("blazqnqbla"));

    return 0;
}

char find_first_unique(char *str) {

    int chars[128] = {0};
    int order[128] = {0};

    for (int i = 0, counter = 1; str[i]; i++) {
        chars[str[i]]++;
        if (order[str[i]] == 0) {
            order[str[i]] = counter;
            counter++;
        }
    }

    int index = 0;

    for (int i = 1, helper = -1; i < 128; i++) {
        if (chars[i] == 1) {
            if (helper == -1) {
                helper = order[i];
                index = i;
            } else {
                if (order[i] < helper) {
                    helper = order[i];
                    index = i;
                }
            }
        }
    }

    return index;

}