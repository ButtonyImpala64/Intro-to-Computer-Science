#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LETTERS_NUM 26

int findShortestMultiSub(char* s, char* t);
bool molded(int mold[], int letters[]);
int try_to_shrink(int index, int tail, int letters[], int mold[], char *s);

int main() {

    char *s = "abcaefght", *t = "abcfa";

    printf("%d\n", findShortestMultiSub(s, t));


    return 0;
}

int findShortestMultiSub(char* s, char* t) {

    int mold[LETTERS_NUM] = {0};
    int letters[LETTERS_NUM] = {0};

    int n = 0, m = 0;

    while (t[m]) {
        mold[t[m]-'a']++;
        m++;
    }

    //for (int i = 0; i < 26; i++)
      //  printf("%d ", mold[i]);

    while (s[n])
        n++;

    bool acheived = false;
    int cur = 0, min, tail, move;

    for (int i = 0; i < n; i++) {
        letters[s[i]-'a']++;
        cur++;
        if (!acheived && molded(mold, letters)) {
            acheived = true;
            min = cur;
            tail = 0;
        }
        if (acheived) {
            move = try_to_shrink(i, tail, letters, mold, s);
            cur -= move;
            tail += move;
        }

        if (cur < min)
            min = cur;
    }

    if (acheived)
        return min;
    else
        return -1;

}

//compares letters and mold with deviation parameter
bool molded(int mold[], int letters[]) { 
    
    for (int i = 0; i < LETTERS_NUM; i++) {
        if (mold[i] != 0) {
            if (letters[i] < mold[i]) return false;
        }
    }

    return true;

}

int try_to_shrink(int index, int tail, int letters[], int mold[], char *s) {

    int counter = 0;

    while (letters[s[tail+counter]-'a'] > mold[s[tail+counter]-'a']) {
        counter++;
        letters[s[tail+counter]-'a']--;
    }


    return counter;

}