#include <stdio.h>
#include <stdlib.h>

struct PET{
    char* type;
    char* name;
};

void printList(struct PET *q, int num){
    // print num elements from the array pointed to by pointer q
    int i;
    for (i = 0; i < num; i++){
        struct PET pet;
        pet = q[i];
        printf("pet type = %s, name = %s\n", pet.name, pet.type);
    }
}

void copyList(struct PET *p_source, struct PET *p_dest, int n){
    // copy n elements from array point p_source to array pointer p_dest
    if (p_source == NULL) printf("p_source cannot be NULL");

    int i;
    for (i = 0; i < n; i++){
        p_dest[i] = p_source[i];
    }
    return;
}

struct PET * copyList2(struct PET *p_source, int n){
    // copy n elements from array point p_source to array pointer p_dest
    if (p_source == NULL) printf("p_source cannot be NULL");

    // allocate memory to p_dest to represent an array of n elements of stuct PET
    struct PET *p_dest = (struct PET *) malloc(n * sizeof(struct PET));
    int i;
    for (i = 0; i < n; i++){
        p_dest[i] = p_source[i];
    }
    return p_dest;
}

int main(){
    // want to have a list of pents (up to n = 2)

    int num_pets = 2;
    struct PET *p; // to represent/store a list of pets
    // allocate memory for p to hold num_pets pets

    p = (struct PET *) malloc(num_pets * sizeof(struct PET));

    (*p).type = "cat"; // alternatively we can use ((*p).type, "cat"); but make sure we
    // allocate memory to (*p).type first
    // or you can do p->type = "cat"
    // pr you can do p[0].type = "cat"

    (*p).name = "fluffy"; // or p->name = "fluffy", or p[0].name = "fluffy"

    (p + 1)->type = "dog"; // or (*(p + 1)).type = "dog"
    (p + 1)->name = "spot"; // or (*(p + 1)). name = "spot"

    // print this list of pets
    printf("p is:\n");
    printList(p, 2); // print 2 elemnts in the array pointed two by pointer p

    struct PET *a = (struct PET *) malloc(2 * sizeof(struct PET));
    copyList(p, a, 2);
    printf("a is: \n");
    printList(a, 2);

    struct PET *b;
    b = copyList2(p, 2);
    printf("b is:\n");
    printList(b, 2);

    free(p);
    p = NULL;
    free(a);
    a = NULL;
    free(b);
    b = NULL;
    return 0;
}