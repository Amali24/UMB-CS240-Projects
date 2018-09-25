#include <stdio.h>
int main(){
    char c;
    int newline = 0;
    while(1){
        c = getchar();
        if (c == EOF){
            break;
        }
        if (c == '\n' && newline == 0){
            newline = 1;
            putchar(c);
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