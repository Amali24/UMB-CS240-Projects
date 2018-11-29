#include <stdio.h>
#include <stdlib.h>

struct STRING{
    char *s;
    struct STRING *next;
};

int get_strings(struct STRING *list){
    // read from stdin list of strings and store in 
    // linked list given as input
    printf("called get_strings\n");

    char cin;
    int i = 0;
    int j = 0;

    while(1){
        cin = getchar();
        printf("got a %c\n", cin);
        if(cin == ';' ){
            printf("found a semicolon\n");
            // next
            list[i].s[j] = 0;
            j = 0;
            i++;
            continue;
        }
        if (cin == EOF){
            break;
        }
        list[i].s[j] = cin;
        printf("list[%d].s[%d] = %c\n",i, j, list[i].s[j]);
        j++;
    }
    return i + 1;
}

void sort_strings(struct STRING *list, int num_strings){
    // ascendingly sort strings by length
}

void show_strings(struct STRING *list, int num_strings){
    // print contents of list
    printf("called show_strings\n");

    for (int i = 0; i < num_strings; i++){
        printf("list[%d].s = %s\n", i, list[i].s);
    }
}

int main(){
    struct STRING *list;
    const int MAX_LINES = 100;
    const int MAX_LENGTH = 1000;

    list = (struct STRING*) malloc(MAX_LINES * sizeof(char*));

    for (int i = 0; i < MAX_LINES; i++){
        list[i].s = (char*) malloc(MAX_LENGTH * sizeof(char));
    }

    int num_strings = get_strings(list);
    sort_strings(list, num_strings);
    show_strings(list, num_strings);

    return 0;
}