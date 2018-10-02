#include <stdio.h>

char getLine(char* line){
    int i = 0;
    char c = ' ';

    while (1){
        c = getchar();
        if (c != EOF && c != '\n' && c != '\r'){
            line[i] = c;
            i++;
        }
         else if (c == EOF){
            line[i] = EOF;
            i++;
            line[i] = '\0';
            break;
        }
        else{
            line[i] = c;
            i++;
            line[i] = '\0';
            break;
        }
    }
    return *line;
}

int hasChar(char* s, int length){
    int i;
    for (i = 0; i < length; i++){
      
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\r' && s[i] != EOF){
            return 1;
        }
      
        if (s[i] == '\n' || s[i] == '\r' || s[i] == '\0' || s[i] == EOF){
            return 0;
        }
    }
    return 0;
}

int hasEOF(char* s, int length){
    int i;
    for (i = 0; i < length; i++){
        if (s[i] == EOF){
            return 1;
        }
        if (s[i] == '\n' || s[i] == '\r' || s[i] == '\0'){
            return 0;
        }
    }
    return 0;
}

int main(){
    const int SIZE = 1000;
    int i;

    while (1){
        char line[SIZE];

        getLine(line);

        if (hasChar(line, SIZE)){
            i = 0;
            while (line[i] != EOF && line[i] != '\0'){
                putchar(line[i]);
                i++;
            }
        }
        if (hasEOF(line, SIZE)){
            break;
        }
    }

    return 0;
}