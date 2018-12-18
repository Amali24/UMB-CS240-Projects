#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char* word;
    struct Node* next;
    int length;
};

struct Node* newNode(char* word){
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->word = (char*) malloc(100 * sizeof(char));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

int main (){
    const int MAX_LINE_LEN = 1000;

    char* delim = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    char* text = (char*) malloc(sizeof(char) * MAX_LINE_LEN);

    delim = fgets(delim, MAX_LINE_LEN, stdin);
    text = fgets(text, MAX_LINE_LEN, stdin);

    if (delim == NULL || text == NULL){
        return 1;
    }


    char *token = strtok(text, delim);

    int i = 1; 
    while(1){
        printf("%s,%d", token, i++);

        token = strtok(NULL, delim);

        if(token == NULL) break;

        printf("\n");

    }
    return 0;
}