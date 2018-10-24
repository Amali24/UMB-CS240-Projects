//
//  stringSwap.c
//  
//
//  Created by DT on 10/15/18.
//
//

#include <stdio.h>
#include <stdlib.h> // need this library for the malloc() function
#include <string.h>

#define MAXLEN 10000


void swap(char **a, char **b) {
    char* temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

char* getLine() {
    // read a line and return this line
    char *line;
    size_t length;
    
    //before you use line in the following function, you must allocate (reserve) memory for it
    line = (char *) malloc((unsigned long) MAXLEN * sizeof(char)); // reserve 1000 bytes, meaning line cannot store more than 1000 characters!
    getline(&line, &length, stdin);
    line[strlen(line)-1] = 0; // replace the '\n' character at the end of "line" with the null character

    return line;
}


int main() {
    char *string;
    //string =  getLine();
    
    //printf("this line is: %s", string);
    //printf("!\n");

    char* x = "first";
    char* y = "second";

    printf("Before swap:\nX was: %s\nY was: %s\n", x, y);
    swap(&x, &y);
    printf("After swap:\nX is: %s\nY is: %s\n", x, y);
    return 0;
}