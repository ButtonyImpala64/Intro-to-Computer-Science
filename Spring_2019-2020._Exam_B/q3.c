#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LETTERS_NUM 26

int ShortestSubstring(char *str);
bool equal_to_body(int *body, int *arr, int n);

int main() {

    char *str = "";//"aabcaadefacebaa";

    printf("%d\n", ShortestSubstring(str));


    return 0;
}


int ShortestSubstring(char *str) {
    int n = 0;
    while(str[n])
        n++;

    int body[LETTERS_NUM] = {0};
    int arr[LETTERS_NUM] = {0};
    int shortest = 0;

    


    for (int i = 0; i < n; i++) {
        if (body[str[i] -'a'] == 0)
            body[str[i]-'a']++;
    }

    for (int i = 0, tail = 0, current = 0; i < n; i++) {
        arr[str[i]-'a']++;

        if (equal_to_body(body, arr, n) && current == 0) {
            shortest = current = i+1;
            if (shortest == 1) return shortest;
        } else if (current != 0){

            if (arr[str[tail] - 'a'] - 1 > 0) {
                current--;
                arr[str[tail] - 'a']--;
                tail++;
                arr[str[i]-'a'] --;
                i--;
                continue;
            }

            current++;
            if (current < shortest) {
                shortest = current;
            }
        }


    }

    return shortest;



}


bool equal_to_body(int *body, int *arr, int n) {
    for (int i = 0; i < LETTERS_NUM; i++) {
        if (body[i] > 0 && arr[i] == 0) {
            return false;
        }
        if (body[i] == 0 && arr[i] > 0) {
            return false;
        }
    }

    return true;
}