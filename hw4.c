#include <stdio.h>
#include <stdlib.h>

struct STRING{
    char *s;
    struct STRING *next;
};

void get_strings(struct STRING *list){
    // read from stdin list of strings and store in 
    // linked list given as input
    char *in;
    char cin;
}

void sort_strings(struct STRING *list){
    // ascendingly sort strings by length
}

void show_strings(struct STRING *list){
    // print contents of list
}

int main(){
    struct STRING *list;
    const int MAX_LINES = 100;
    const int MAX_LENGTH = 1000;

    for (int i = 0; i < MAX_LINES; i++){
        list[i].s = malloc(MAX_LENGTH * sizeof(char));
    }

    get_strings(list);
    sort_strings(list);
    show_strings(list);

    return 0;
}