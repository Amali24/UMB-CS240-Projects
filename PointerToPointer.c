#include <stdio.h>
#include <stdlib.h>

char** readLines(int *p){
    int n = *p;
    char** list_of_lines;
    list_of_lines = (char**) malloc(n * sizeof(char*));
    int i;
    for (i = 0; i < n; i ++){
        char *line;
        if (gets(line) == NULL){
            break; // get a line from stdin
        }
        *(list_of_lines + i) = line;
    }
    *p = i;
    return list_of_lines;
}

void printLines(char** list_of_lines, int num_of_lines){
    int i;
    for (i = 0; i < num_of_lines; i ++){
        printf("%s\n", *(list_of_lines + i));
    }
}

int main(int argc, char** argv){
    int n;
    if (argc != 2){
        printf("How to run: %s number\n", argv[0]);
        return 0;
    }
    n = atoi(argv[1]);
    char** lines = readLines(&n);
    printLines(lines, n);
    return 0;    
}