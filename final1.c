#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    const int MAX_LINE_LEN = 1000;

    char* delim = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    char* text = (char*) malloc(sizeof(char) * MAX_LINE_LEN);

    int j = 0;

    fgets(delim, MAX_LINE_LEN, stdin);
    fgets(text, MAX_LINE_LEN, stdin);


    char *token = strtok(text, delim);

    while(1){
    
        token = strtok(NULL, delim);

        if(token == NULL) break;

    }
    return 0;
}