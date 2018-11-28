#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MIN {
    int min;
    int row;
    int col;
};

struct MIN * findMin(int **a, int nrow, int ncol) {
    int min=100000;
    int row=-1, col=-1;
    for (int i=0; i<nrow; i++){
        for (int j=0; j<ncol; j++) {
            if (min > a[i][j]) {
                row = i;
                col = j;
                min = a[i][j];
            }
        }
    }
    struct MIN *p = (struct MIN *) malloc(sizeof(struct MIN));

    p->min = min;
    p->row = row+1;
    p->col = col+1;

    return p;
}

int main(){
    int** matrix;
    int max_rows = 100;
    int max_cols = 100;
    matrix = (int **)malloc(max_rows * sizeof(int *)); 
    for (int i = 0; i < max_rows; i++) 
         matrix[i] = (int *)malloc(max_cols * sizeof(int)); 
    int row = 0;
    int col = 0;

    int isEOF = 0;
    while (!isEOF){
        char temp;
        temp = getchar();
        if (temp == '\n'){
            row++;
            col = 0;
            continue;
        } 
        if (temp >= '0' && temp <= '9'){
            matrix[row][col] = temp - '0';
            col++;
        }
        else if (temp == EOF){
            row++;
            isEOF = 1;
        }
    }
    struct MIN* p = findMin(matrix, row, col);
    printf("Min=%d, Row=%d, Column=%d", p->min, p->row, p->col);

    return 0;
}