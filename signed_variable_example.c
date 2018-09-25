#include <stdio.h>

int main(){
    int i; // a "signed variable"
    i = 0xaa; // value is 170
    printf("i = %d\n", i);

    i = '\xaa';
    printf("i = %d\n", i);

    char c; //by default, this is signed
    c = '\xaa';
    printf("as a character, c = %c\n", c);
    printf("as a decimal value, c = %d\n", c);

    i = c;
    printf("i = %d\n", i);

    return 0;
}