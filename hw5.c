#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Position{
    int line;
    int offset;
    struct Position *next;
};

struct TreeNode{
    char *word;
    struct Position *position;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(char* word, struct Position pos){
    struct TreeNode *new_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    new_node->position = (struct Position*) malloc(1000 * sizeof(struct Position));
    new_node->position[0] = pos;
    strcpy(new_node->word, word);
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct TreeNode *insertNode(struct TreeNode *tree, char *word, struct Position pos){
    //printf("passed word: %s\n", word);
    //printf("passed position: %d, %d\n", pos.line, pos.offset);

    if(tree == NULL){
        tree = newNode(word, pos);
    }

    if(strcmp(word, tree->word) < 0){
        // GO LEFT
        tree = insertNode(tree->left, word, pos);
    }

    else if(strcmp(word, tree->word) < 0){
        // GO RIGHT
        tree = insertNode(tree->right, word, pos);
    }

    else{
        // UPDATE NODE
    }

    return tree;
}

struct TreeNode *removeWord(struct TreeNode *tree, char *word){
    return NULL;
}

struct TreeNode *removePosition(struct TreeNode *tree, struct Position pos){
    return NULL;
}

struct TreeNode *removeLine(struct TreeNode *tree, int line){
    return NULL;
}

void output(struct TreeNode *tree){
    // if can go left, do
    // if can't go left, go right.
    // if can't go either, print
    // go up
        if (tree != NULL){
            output(tree->left);
            printf("%s \n", tree->word);
            output(tree->right);
        }

}

int main(){
    const int MAX_NUM_LINES = 1000;
    const int MAX_NUM_COMMANDS = 100;
    const int MAX_LINE_LENGTH = 1000;
    const int MAX_NUM_NODES = 1000;

    char commands[MAX_NUM_COMMANDS][MAX_LINE_LENGTH];
    char text[MAX_NUM_LINES][MAX_LINE_LENGTH];

    int isCommandSection = 1;
    char input[MAX_LINE_LENGTH];

    int num_cmds = 0;
    int num_lines = 0;


    //TODO: Allocate memory for tree

    while (isCommandSection){
        if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL){
            break;
        }
        
        if (strcmp(input, "END\n") == 0){
            isCommandSection = 0;
            continue;
        }

        strcpy(commands[num_cmds++], input);

    }

    while (fgets(input, MAX_LINE_LENGTH, stdin) != NULL){
        strcpy(text[num_lines++], input);
    }

    /*printf("Commands:\n");

    for (int i = 0; i < num_cmds; i++){
        printf("%s", commands[i]);
    }

    printf("\nText:\n");

    for (int i = 0; i < num_lines; i++){
        printf("%s", text[i]);
    }

    printf("\n");*/


    struct TreeNode *root;

    root = NULL;

    char delim[] = " \t\r\n\v\f";

    for (int i = 0; i < num_lines; i++){
        int j = 0;
        char *token = strtok(text[i], delim);

        while(1){
            //printf( " %s\n", token );
    
            token = strtok(NULL, delim);

            if(token == NULL) break;

            // add token to tree
            struct Position pos;
            pos.line = i + 1;
            pos.offset = j++;
            pos.next = NULL;

            
            root = insertNode(root, token, pos);
        }

    }

    // TODO: COMMAND PROCESSING GOES HERE

    output(root);
    return 0;
}