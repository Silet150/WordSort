#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000
#define MAXWORD 200
#define MAXWORDL 50
#define SEPAR printf("----------------------\n");

int mystrcmp(const char *a, const char *b) {
    while (*a && *b) {
        char ca = tolower(*a);
        char cb = tolower(*b);

        if (ca != cb)
            return ca - cb;

        a++;
        b++;
    }
    return tolower(*a) - tolower(*b);
}

void print2darr(char wordArr[][MAXWORDL], int size){
    for(int i = 0; i < size; i++){
        for (int j = 0; j < MAXWORDL && wordArr[i][j] != '\0'; j++) {

            printf("%c", wordArr[i][j]);
        }
        printf("\n");
    }
}

void printarr(char arr[]){
    int i = 0;
    while(arr[i] != '\0')
        {
            printf("%c", arr[i]);
            i++;
        }
    printf("\n");
}

void bublsort(char arr[][MAXWORDL], int size){
    char temp[MAXWORDL];
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(mystrcmp(arr[j], arr[j+1]) > 0)
            {

                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
            memset(temp, 0, MAXWORDL);
        }
    }
}

int getline(char arr[], int maxlen) {
    int c, i;
    
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        arr[i] = c;
    
    
    arr[i] = '\0';
    return i;
}


int getword(char inputArr[], char wordArr[][MAXWORDL]){  
    int k = 0;
    int i = 0;
    int j = 0;
    while(inputArr[i] != '\0' && i < MAX)
    {
        if(inputArr[i]== ' ')
            {
                i++;
                continue;
            }
        j = 0;
        while(inputArr[i] != ' ' && inputArr[i] != '\0' && j < MAXWORDL - 1)
        {
            wordArr[k][j] = inputArr[i];
            i++;
            j++;
        }
        wordArr[k][j] = '\0';
        k++;
    }
    return k;
}

int main(){
    char inputArr[MAX];
    char wordArr[MAXWORD][MAXWORDL];

    getline(inputArr, MAX);
    printf("input: \n");
    printarr(inputArr);
    SEPAR

    int wordc = getword(inputArr, wordArr);
    printf("by word");
    print2darr(wordArr, wordc);
    SEPAR

    bublsort(wordArr, wordc);
    printf("sorted array\n");
    SEPAR

    print2darr(wordArr, wordc);
    SEPAR

    printf("word count: %d", wordc);
    return 0;
}
