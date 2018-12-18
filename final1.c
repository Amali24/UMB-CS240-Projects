#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    const int MAX_LINE_LEN = 1000;

    char* delim = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    char* text = (char*) malloc(sizeof(char) * MAX_LINE_LEN);

    delim = fgets(delim, MAX_LINE_LEN, stdin);
    text = fgets(text, MAX_LINE_LEN, stdin);

    if (delim == NULL || text == NULL){
        return 1;
    }


    char *token = strtok(text, delim);

    int i = 1; 
    while(1){
        printf("%s,%d", token, i++);

        token = strtok(NULL, delim);

        if(token == NULL) break;

        printf("\n");

    }
    return 0;
}