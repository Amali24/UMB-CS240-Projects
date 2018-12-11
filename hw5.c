#include <stdio.h>

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