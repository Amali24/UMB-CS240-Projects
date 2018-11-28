#include <stdio.h>

struct STRING{
    char *s;
    struct STRING *next;
};

void get_strings(struct STRING *list){
    // read from stdin list of strings and store in 
    // linked list given as input
}

void sort_strings(struct STRING *list){
    // ascendingly sort strings by length
}

void show_strings(struct STRING *list){
    // print contents of list
}

int main(){
    struct STRING *list;

    get_strings(list);
    sort_strings(list);
    show_strings(list);

    return 0;
}