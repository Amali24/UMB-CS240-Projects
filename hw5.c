#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_lines = 0;


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
    //printf("made a node\n");
    new_node->position = (struct Position*) malloc(1000 * sizeof(struct Position));
    //printf("made a pos\n");
    new_node->position->line = pos.line;
    new_node->position->offset = pos.offset;
    //printf("assigned a pos\n");
    new_node->position->next = NULL;
    new_node->word = (char*) malloc(100 * sizeof(char));
    //printf("made a string\n");
    strcpy(new_node->word, word);
    //printf("copied string \"%s\" to node\n", word);
    new_node->left = new_node->right = NULL;
    //printf("set the branches to null\n\n");
    return new_node;
}

struct Position* newPosition(int line, int offset){
    struct Position *pos = (struct Position*) malloc(sizeof(struct Position*));
    //printf("Made a new postion\n");
    pos->line = line;
    //printf("set line to %d\n", line);
    pos->offset = offset;
    //printf("set offset to %d\n", offset);
    pos->next = NULL;
    //printf("set next to null\n\n");
    return pos;
}

struct TreeNode *insertNode(struct TreeNode *tree, char *word, struct Position pos){
    //printf("passed word: %s\n", word);
    //printf("passed position: %d, %d\n\n", pos.line, pos.offset);

    if(tree == NULL){
        //printf("tree was null\n");
        struct TreeNode *temp = newNode(word, pos);
        //printf("made new node...\n\n");
        return temp;
    }

    if(strcmp(word, tree->word) < 0){
        //printf("%s < %s, going left\n", word, tree->word);
        tree->left = insertNode(tree->left, word, pos);
    }

    else if(strcmp(word, tree->word) > 0){
        //printf("%s > %s, going right\n", word, tree->word);
        tree->right = insertNode(tree->right, word, pos);
    }

    else if (strcmp(word, tree->word) == 0){
        //printf("word found\n");
        while(tree->position->next != NULL){
            tree->position = tree->position->next;
            //printf("going to next position\n");
        }
        tree->position->next = newPosition(pos.line, pos.offset);
        //printf("added position\n\n");
    }

    return tree;
}

struct TreeNode* getSmallestNode(struct TreeNode *tree){
    printf("looking for smallest node\n");
    struct TreeNode *current = tree;
    while (current->left != NULL){
        current = current->left;
        printf("left found, going left\n");

    }
    printf("no left found, returning \"%s\" node\n", current->word);
    return current;
}

struct TreeNode *removeWord(struct TreeNode *tree, char *word){
    if (tree == NULL){ 
        printf("hit base case, tree == NULL\n");
        return NULL;
    }

    if (strcmp(word, tree->word) < 0){
        printf("%s < %s, going left\n", word, tree->word);
        tree->left = removeWord(tree->left, word);
    }
    else if (strcmp(word, tree->word) > 0){
        printf("%s > %s, going right\n", word, tree->word);
        tree->right = removeWord(tree->right, word);
    }

    else{
        printf("found %s\n", word);

        if(tree->left == NULL){
            printf("node has no left\n");
            struct TreeNode *temp = tree->right;
            printf("temp = right\n");
            free(tree);
            printf("deleted node\n");
            return temp;
        }

        if(tree->right == NULL){
            printf("node has no right\n");
            struct TreeNode *temp = tree->left;
            printf("temp = right\n"); 
            free(tree);
            printf("deleted node\n");
            return temp;
        }

        printf("node has two children: \"%s\" and \"%s\"\n", tree->left->word, tree->right->word);

        struct TreeNode *temp = getSmallestNode(tree->right);
        printf("Temp's word = \"%s\"\n", temp->word);
        tree->word = temp->word;
        tree->position = temp->position;

        tree->right = removeWord(tree->right, temp->word);
    }
    return tree;
}

struct TreeNode *removePosition(struct TreeNode *tree, struct Position pos){
    return NULL;
}

struct TreeNode *removeLine(struct TreeNode *tree, int line){
    return NULL;
}

void outputAlpha(struct TreeNode *tree){
    // if can go left, do
    // if can't go left, go right.
    // if can't go either, print
    // go up
        if (tree != NULL){
            outputAlpha(tree->left);
            printf("%s @ (%d, %d)\n", tree->word, tree->position->line, tree->position->offset);
            outputAlpha(tree->right);
        }

}

struct TreeNode* findByPosition(struct TreeNode *tree, int line, int offset){
    if (tree == NULL) {
        return NULL;
    }   
    struct Position *pos = tree->position;
    while (pos != NULL){
        if (pos->line == line && pos->offset == offset){
            return tree;
        }
        pos = pos->next;
    }
    struct TreeNode *node = findByPosition(tree->left, line, offset);
    if (node == NULL) return findByPosition(tree->right, line, offset);
    else return node;
}

void output(struct TreeNode *tree){
    for (int line = 1; line <= num_lines; line++){
        int offset = 0;
        while(1){
            struct TreeNode *node = findByPosition(tree, line, offset++);
            if (node == NULL) break;
            //offset ++;
            if (offset >= 2) printf(" ");
            printf("%s", node->word);
        }
        if (line < num_lines) printf("\n");
    }
}

int main(){
    const int MAX_NUM_LINES = 100;
    const int MAX_NUM_COMMANDS = 100;
    const int MAX_CMD_LENGTH = 100;
    const int MAX_LINE_LENGTH = 10000;
    const int MAX_NUM_NODES = 1000;

    char commands[MAX_NUM_COMMANDS][MAX_CMD_LENGTH];
    char text[MAX_NUM_LINES][MAX_LINE_LENGTH];

    int isCommandSection = 1;
    char input[MAX_LINE_LENGTH];

    int num_cmds = 0;

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

    printf("\n\n\n");
    */


    struct TreeNode *root = NULL;

    char delim[] = " \t\r\n\v\f";

    for (int i = 0; i < num_lines; i++){
        int j = 0;
        //printf("new for loop (156), i = %d, j = %d\n", i, j);
        //printf("current line is \"%s\"\n", text[i]);

        char *token = strtok(text[i], delim);

        while(1){
            //printf("Token: %s\n", token );

            // add token to tree
            struct Position *pos = newPosition(i + 1, j);
            //printf("made a pos with %d, %d\n\n", i + 1, j);
            j++;


            root = insertNode(root, token, *pos);
    
            token = strtok(NULL, delim);

            if(token == NULL) break;


        }

    }

    // TODO: COMMAND PROCESSING GOES HERE
    printf("commands:\n");
    for(int i = 0; i < num_cmds; i++){
        //printf("iteration #%d of command for-loop\n", i + 1);
        
        char *tok = strtok(commands[i], delim);
        //printf("token = \"%s\"\n", tok);


        if(strcmp(tok, "RL")==0){
            //remove line
            tok = strtok(NULL, delim);
            int line_rem = atoi(tok);
            printf("removing line %d\n", line_rem);
        }
        else if (strcmp(tok, "R") == 0){
            //remove word
            tok = strtok(NULL, delim);
            if (tok[0] > '0' && tok[0] < '9'){
                //remove by position
                int pos_line = atoi(tok);
                tok = strtok(NULL, delim);
                int pos_off = atoi(tok);
                printf("removing word @ (%d, %d)\n", pos_line, pos_off);
            }
            else{
                //remove by word
                char* word_rem = (char*) malloc(MAX_CMD_LENGTH * sizeof(char));
                strcpy(word_rem, tok);
                printf("removing word \"%s\"\n", word_rem);
                removeWord(root, word_rem);
            }
        }
        else if(strcmp(tok, "I") == 0){
            //insert word
            tok = strtok(NULL, delim);
            char* word_ins = (char*) malloc(MAX_CMD_LENGTH * sizeof(char));
            strcpy(word_ins, tok);

            tok = strtok(NULL, delim);
            int pos_line = atoi(tok);
            tok = strtok(NULL, delim);
            int pos_off = atoi(tok);

            printf("inserting word \"%s\" @ (%d, %d)\n", word_ins, pos_line, pos_off);

        }
    }

    printf("\n\n");
    //outputAlpha(root);
    //output(root);
    printf("\n");
    return 0; 
}