// Reverse a given linked list.
#include<stdlib.h>
#include <stdio.h>


typedef struct list {
    int data;
    struct list *next;
} list;


list* reverse_list(list *l) {
    if (l->next == NULL) return l;

    list *prev, *curr, *next;

    prev = NULL;
    curr = l;
    next = l->next;

    do {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
     } while (next != NULL);

    curr->next = prev;

    return curr;
}

void print_list(list *l) {
    while (l->next != NULL) {
        printf("%d->", l->data);
        l = l->next;
    }

    printf("%d\n", l->data);

}


int main(int argc, char **argv) {
    list* l;
    l = malloc(sizeof(list));
    
    l->data = 0;

    list* head = l;

    for (int i = 1; i<=10; i++) {
        list* p;
        p = malloc(sizeof(list));
        p->data = i;
        p-> next = NULL;
        l->next = p;
        l = p;
    }
    printf("LIST: ");
    print_list(head);   

    head = reverse_list(head);

    printf("REVERSED LIST: ");
    print_list(head);   

}
