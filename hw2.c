//
// hw.2
//
//
// Created by Andrew Thomas on 10/1/18
//
//

#include <stdio.h>

#define MAXLEN 10000


char[][] splitString(char[] s, char d){
    // implement the splitting algorithm
    // now reading string s to extract words

    int n = 0; // order of the word in the string
    int i = 0;     // position in string s
    int j = 0; // position in word
    char c;

    // check if s is empty

    if (s[0] == 0){
        // s is empty
        word[0][0] = 0;

    }
    while(1){
        c = s[i];
            

        if (c == d){
            // see the delimiter char
            word[n][j] = 0; // null character
            j = 0;
            n++; // ready for next word
        }
        else{
            word[n][j] = c;
            j++;
        }
        i++;

        // is this the last character of string s
        if (s[i] == 0){
            // check if previous character is delimiter or not
            if (c == d){
                // previous character is the same as delimiter
                word[n][0] = 0; // empty word
            }
            else {
                break;
            }
        }
    
    }

    // so far we have (n+1) words: word[0], word[1], ..., word[n]
    // create a special word to make the end of the list of words
    // so tht I print them, when seeing this special word, I know
    // I must stop
    word[n+1][0] = EOF;
    return word;

}

int main(){
    char s[MAXLEN]; // String input
    char d;         // Delimiter

    // read input from stdinput
    char c;
    int i = 0;
    while(1){
        c = getchar();
        if (c == '\n'){
            // Reach end of first line
            break;
        }
        else{
            s[i] = c;
            i++;
        }
    }
    s[i] = 0; // same as '\0'

    // read the delimiter from stdin
    d = getchar();

    // after I know d and s I am now calling the function
    char **word; // word[n] is the (n+1)th word in the string
    splitString(s, d, word);

    // print the words
    int n = 0;
    while(1){

        if (word[n][0] == EOF) break;

        printf("%s\n", word[n]);
        n++;
        // we need to break out of this loop somehow
    }
}