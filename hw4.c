#include <stdio.h>
#include <stdlib.h>

struct STRING{
    char *s;
    struct STRING *next;
};

void get_strings(struct STRING *list){
    // read from stdin list of strings and store in 
    // linked list given as input
    char cin;
    int i = 0;
    int j = 0;

    while(1){
        cin = getchar();
        if(cin == ';' ){
            // next
            list[i].s[j] = 0;
            j = 0;
            i++;
        }
        if (cin == EOF){
            break;
        }
        list[i].s[j] = cin;
    }
}

void sort_strings(struct STRING *list){
    // ascendingly sort strings by length
}

void show_strings(struct STRING *list){
    // print contents of list
    printf("show_string\n");
    printf("%s\n", list[0].s);
}

int main(){
    struct STRING *list;
    const int MAX_LINES = 100;
    const int MAX_LENGTH = 1000;

    list = (struct STRING*) malloc(MAX_LINES * sizeof(char*));

    for (int i = 0; i < MAX_LINES; i++){
        list[i].s = (char*) malloc(MAX_LENGTH * sizeof(char));
    }

    get_strings(list);
    sort_strings(list);
    show_strings(list);

    return 0;
}