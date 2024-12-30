#include <stdio.h>
#include <stdlib.h>


void add_element(int *bitset, int element) {
    *bitset |= (1 << element);  
}


void remove_element(int *bitset, int element) {
    *bitset &= ~(1 << element);  
}


int is_member(int bitset, int element) {
    return (bitset & (1 << element)) != 0; 
}


void display_set(int bitset, int size) {
    printf("Set contains: { ");
    for (int i = 0; i < size; i++) {
        if (is_member(bitset, i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    int bitset = 0;  
    int size = 10;   


    add_element(&bitset, 3);   
    add_element(&bitset, 5);   
    add_element(&bitset, 7);   
    add_element(&bitset, 9);   

   
    display_set(bitset, size);


    printf("Is 3 in the set? %s\n", is_member(bitset, 3) ? "Yes" : "No");
    printf("Is 4 in the set? %s\n", is_member(bitset, 4) ? "Yes" : "No");

    
    remove_element(&bitset, 5);  
    remove_element(&bitset, 9);  

  
    display_set(bitset, size);

    return 0;
}