#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char* word;
    struct Node* next;
    int length;
    int position;
};

struct Node* newNode(char* word, int position){
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->word = (char*) malloc(10000 * sizeof(char));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    new_node->position = position;
    
    int i = 0;
    while (word[i] != 0){
        i++;
    }

    new_node->length = i;

    return new_node;
}

struct Node *insertNode(struct Node* head, struct Node *newNode){
    if (head == NULL){
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->length <= newNode->length){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void output(struct Node* head){
    printf("\nwe're in output\n");
    while(1){
        printf("%s,%d", head->word, head->position);
        head = head->next;
        if (head == NULL) break;
        printf("\n");
    }
}

int main (){
    const int MAX_LINE_LEN = 1000;

    char* delim = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    char* text = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    printf("malloc'ed strings\n");

    delim = fgets(delim, MAX_LINE_LEN, stdin);
    text = fgets(text, MAX_LINE_LEN, stdin);
    //printf("text: %s\n", text);

    if (delim == NULL || text == NULL){
        return 1;
    }


    char *token = strtok(text, delim);

    struct Node* head = NULL;
    printf("made a head node\n");

    int i = 1; 
    while(1){
        insertNode(head, newNode(token, i++));
        printf("inserted node with \"%s\" @ %d\n", token, i - 1);

        //printf("%s,%d", token, i++);

        token = strtok(NULL, delim);

        if(token == NULL){
            printf("null token breaking \n");
            break;
        }

        //printf("\n");
    }

    output(head);

    return 0;
}