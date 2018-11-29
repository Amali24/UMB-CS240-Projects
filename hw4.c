#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STRING{
    char *s;
    struct STRING *next;
};

int get_strings(struct STRING *list){
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
            list[i].next = &list[i+1];
            j = 0;
            i++;
            continue;
        }
        if (cin == EOF){
            list[i].next = NULL;
            break;
        }
        list[i].s[j] = cin;
        j++;
    }
    return i + 1;
}

void sort_strings(struct STRING *list, int num_strings){
    // ascendingly sort strings by length

    int swapped, i; 
    struct STRING *ptr1; 
    struct STRING *lptr = NULL; 
  
    /* Checking for empty list */
    if (list->next == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = list; 
  
        while (ptr1->next != lptr) 
        { 
            if (strlen(ptr1->s) > strlen(ptr1->next->s)) 
            {  
                char* temp = ptr1->s; 
                ptr1->s = ptr1->next->s; 
                ptr1->next->s = temp; 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
}

void show_strings(struct STRING *list, int num_strings){
    // print contents of list
    printf(" ");
    for (int i = 0; i < num_strings; i++){
        printf("%s\n", list[i].s);
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