// Define a dictionary data structure with constant time insert, lookup and search.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 101

unsigned int hash(int x) {
    // The hashing algorithm (note: there is no logic behind this)
    unsigned int h = 0;
    for (int i = 0; i < x; i++) {
        h += ((int)pow((double)x, (double)x-i))*i;
    }

    return h % HASH_SIZE;
}

// A node of the linked list
typedef struct item {
    int key, value;
    struct item *next;
} item;

// Utility function to create node of the linked list
item* new_item(int key, int value) {
    item* p;
    p = malloc(sizeof(item));
    p-> key = key;
    p->value = value;
    p->next = NULL;
    return p;
}




int lookup(item** table, int key) {
    // Look up a key in the dictionary and return its value
    unsigned int h = hash(key);
    for (item* p = table[h]; p != NULL; p = p->next) {
        if (p->key == key) return p->value;
    }
    return 0;
}

void insert(item** table, int key, int value) {
    // Insert a key-value pair in the dictionary.
    unsigned int h = hash(key);

    item* p = new_item(key, value);
    p->next = table[h];
    table[h] = p;
}



// The hash table is an array of linked lists. 
static item* HASH_TABLE[HASH_SIZE];

int main() {
    int key, value, lookup_value;
    key = 10;
    value = 15;
    insert(HASH_TABLE, 10, 15);

    lookup_value = lookup(HASH_TABLE, key);
    
    printf("%d %d\n", value, lookup_value);

    return !(value == lookup_value);
}


