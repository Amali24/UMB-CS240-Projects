//
//  hw2.c
//  
//
//  Created by Andrew Thomas on 10/1/18.
//
//

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10000


char** splitString(char s[], char d) {
    printf("entered splitString\n");
    char **word  = malloc(100000 * sizeof(char));
    printf("allocated memory\n");
    // implement the splitting requirement
    // now reading string s to extract words
    int n = 0; // order of the word in the string
    printf("made word iterator\n");
    int i=0; // position in string s
    printf("iterator for string\n");
    int j=0; // position in word
    printf("iterator for word\n");
    char c;
    printf("made temp char\n");
    // check if s is empty
    
    if (s[0] == 0) {
        printf("s was empty\n");
        // s is empty
        word[0][0]=0;
        
    }
    
    
    while (1) {
        printf("in the while loop\n");
        c = s[i];
        printf("c = %c\n", s[i]);
        
        if (c==d) {
            printf("saw delimeter\n");
            // see the delimiter char
            word[n][j]=0; // null character
            printf("put in a nullchar\n");
            j=0;
            n++; // ready for next word
            printf("moving to next word\n");
        }
        else {
            printf("in the else\n");
            word[n][j]=c;
            printf("word[%d][%d] = %c", n, j, c);
            j++;
        }
        i++;
        
        // is this the last character of string s
        if (s[i]==0) {
            // check if previous character is delimiter or not
            if (c == d) {
                // previous character is same as delimiter
                word[n][0]=0; // empty word
            }
            else {
                break;
            }
        }
        
    }
    
    // so far we have (n+1) words: word[0], word[1], ..., word[n]
    // create a special word to make the end of the list of words
    // so that I print them, when seeing this special word, I know I must stop
    word[n+1][0]=EOF;
    return word;
}

int main() {
    char s[MAXLEN]; // string input
    printf("created string in main\n");

    char d; // delimiter
    printf("created del character in main\n");
    
    // read input from stdinput
    char c;
    printf("created temp char in main\n");
    int i = 0;
    printf("created iterator in main\n");
    while(1) {
        printf("entered while loop\n");
        c = getchar();
        printf("got %c from input\n", c);
        if (c== '\n') {
            printf("found end of line\nbreaking loop\n");
            // reach end of first line
            break;
        }
        else {
            s[i]=c;
            printf("added to string\n");
            i++;
            printf("incremented iterator");
        }
    }
    s[i]=0; // same as '\0'
    printf("added null to the end\n");
    
    // read the delimiter from stdin
    d = getchar();
    printf("stored delimeter\n");
    
    // after I know d and s, I am now calling the function
    char** word; // word[n] is the (n+1)th word in the string
    printf("created 2d pointer\n");
    word = splitString(s, d);
    printf("successfully called splitString()");
    
    // print the words
    int n=0;
    printf("made new word iterator\n");
    while(1) {
        
        if (word[n][0]==EOF){
            printf("found EOF\n");
            break;
        }
        
        int i = 0;
        printf("made new iterator for letters\n");

        while (word[n][i] != 0){
            printf("%c", word[n][i]);
        }
        printf("moving to next word\n");
        n++;        
    }   
}