#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LETTERS_NUM 26

bool IsWord (char mainWord[], char testWord[]);
int WordScore (char *dictionary[], int n, char *word);
void match(int arr[], char *string);
void fill_zeros(int arr[]);

int main() {

    char *mainWord = "technion";
    char *testWord = "iconic";
    char *dictionary[] = {"te", "tes", "wow", "tet", "est"};
    char *word = "test";
    int n = 5;

    printf("%d\n", WordScore(dictionary, n, word));

    return 0;
}

bool IsWord (char mainWord[], char testWord[]) {

    int n = 0, m = 0;

    while (mainWord[n])
        n++;

    while (testWord[m])
        m++; 

    int arr1[LETTERS_NUM] = {0};
    int arr2[LETTERS_NUM] = {0};

    int res = 1;

    for (int i = 0; i < n; i++) {
        arr1[mainWord[i]-'a']++;
    }

    for (int i = 0; i < m; i++) {
        arr2[testWord[i]-'a']++;
    }

    for (int i = 0; i < LETTERS_NUM; i++)
    {
        if (arr1[i] < arr2[i])  {
            res = 0; //return false
        }

    }

    return res;
    

}

int WordScore (char *dictionary[], int n, char *word) {

    int main[LETTERS_NUM] = {0};
    int test[LETTERS_NUM] = {0};
    int possible = 1, counter = 0;

    match(main, word);

    for (int i = 0; i < n; i++) {
        fill_zeros(test);
        match(test, dictionary[i]);

        possible = 1;
        for (int j = 0; j < LETTERS_NUM; j++)
        {
            if (main[j] < test[j])  {
                possible = 0; //return false
            }
        }

        counter += possible;
    }

    return counter;

}

void fill_zeros(int arr[]) {

    for (int i = 0; i < LETTERS_NUM; i++)
        arr[i] = 0;

}

void match(int arr[], char *string) {
    int n = 0;

    while (string[n])
        n++;

    for (int i = 0; i < n; i++) {
        arr[string[i]-'a']++;
    }

}