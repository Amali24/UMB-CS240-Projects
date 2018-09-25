/*
Write a program: RemoveEmptyLines.c
- Input: a text file
- Output: a text file exactly same as the input file except that all the empty lines
        are removed
Requirement: the only input/output functions you can use are getchar() and
putchar(). If you want to use any other function, you have to implement it by
yourself.
To run your program at your local computer, type the following at the command line
prompt:
RemoveEmptyLines < input_file > output_file where you provide input_file as the name of
the input file and output_file as the name of the output file.
*/

#include <stdio.h>

int main(){
    char c;
    short int newline = 0;
    while(1){
        c = getchar();
        if (c == EOF){
            break;
        }
        if (c == '\n' && newline == 0){
            newline = 1;
            putchar('\n');
            continue;
        }
        while (newline == 1 && c == '\n'){
            c = getchar();
        }
        putchar(c);
        newline = 0;
    }
    return 0;
}
