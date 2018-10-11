#include <stdio.h>

void swap(int *x, int *y) {
   
   int temp;
   temp = *x;   
   *x = *y;
   *y = temp;
  
   return;
}

int main(){
    int x;
    x = getchar() - '0';
    getchar();
    int y;
    y = getchar() - '0';

    printf("Before swap, the 1st digit is %d, the 2nd digit is %d\n", x, y);
    swap (&x, &y);
    printf("After swap, the 1st digit is %d, the 2nd digit is %d\n", x, y);

    return 0;
}
