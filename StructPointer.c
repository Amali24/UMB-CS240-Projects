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

    // priont this list of pets

    printList(p, 2); // print 2 elemnts in the array pointed two by pointer p

}