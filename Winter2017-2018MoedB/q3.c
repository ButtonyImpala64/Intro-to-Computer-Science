#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int GetKShortSubstring(char *str, int k);
bool is_abund(int letters[], int k);

int main() {

    char *str = "deadbeef";
    int k = 3;

    printf("%d\n", GetKShortSubstring(str, k));


    return 0;
}

int GetKShortSubstring(char *str, int k) {

    int max = 0, n = 0, tail = -1, cur = 0;

    int letters[26] = {0};

    while(str[n])
        n++;

    for (int i = 0; i < n; i++) {
        letters[str[i]-'a']++;
        if (is_abund(letters, k-1) && tail == -1) tail = 0;
        if (is_abund(letters, k) == true) {

            for (int j = tail; ; j++, cur--) {
                letters[str[j]-'a']--;
                if (str[j] == str[i]) {
                    tail = j+1;
                    cur--;
                    break;
                }
            }

        }
        cur++;
        if (cur > max) max = cur;
    }

    if (tail > -1) return max;

    return 0;


}

bool is_abund(int letters[], int k) {

    for (int i = 0; i < 26; i++) {
        if (letters[i] == k) return true;
    }

    return false;

}