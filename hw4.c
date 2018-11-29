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

void sort_strings(struct STRING *list){
    // ascendingly sort strings by length

    int swapped, i; 
    struct STRING *ptr; 
    struct STRING *last_ptr = NULL; 
  
    // Checkfor empty list */
    if (list->next == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr = list; 
  
        while (ptr->next != last_ptr) 
        { 
            if (strlen(ptr->s) > strlen(ptr->next->s)) 
            {  
                char* temp = ptr->s; 
                ptr->s = ptr->next->s; 
                ptr->next->s = temp; 
                swapped = 1; 
            } 
            ptr = ptr->next; 
        } 
        last_ptr = ptr; 
    } 
    while (swapped);
}

void show_strings(struct STRING *list, int num_strings){
    // print contents of list
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
    sort_strings(list);
    show_strings(list, num_strings);

    return 0;
}