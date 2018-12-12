#include <stdio.h>
#include <stdlib.h>

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

struct TreeNode *insertNode(struct TreeNode *tree, char *word, struct Position pos){

    if (tree == NULL){
        struct TreeNode *newNode = (struct TreenNode*) malloc(sizeof(struct TreeNode*));
        
        newNode->word = (char*) malloc(sizeof(char) * 100);
        newNode->word = word;

        newNode->position = (struct Position*) malloc(sizeof(struct Position*));
        newNode->position = &pos;

        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    if (word < tree->word){
         tree->left  = insert(tree->left, word, pos); 
    }
    else if (word > tree->word){
         tree->right  = insert(tree->right, word, pos); 
    }

    return tree;
}

struct TreeNode *removeWord(struct TreeNode *tree, char *word){

}

struct TreeNode *removePosition(struct TreeNode *tree, struct Position pos){

}

struct TreeNode *removeLine(struct TreeNode *tree, int line){

}

void output(struct TreeNode *tree){

}

int main(){
    
}