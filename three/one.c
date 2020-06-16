// Using stacks, validate a given string containing parentheses:
// "(()()(()))"" -> VALID
// "((())))" -> INVALID
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct list {
    char c;
    struct list *next;
} list;

typedef struct stack {
    list *head;
    int length;
} stack;


stack* new_stack() {
    stack* s;
    s = malloc(sizeof(stack));
    s->head = NULL;
    s->length = 0;
    return s;
}

void push(char x, stack *s) {
    list* p;
    
    p = malloc(sizeof(list));

    p->c = x;
    p->next = s->head;
    s->head = p;

    s->length++;
}


void pop(stack *s) {
    if (s->length == 0) return;
    list* p;
    p = s->head;
    s->head = p->next;
    free(p);

    s->length--;
}


int main(int argc, char** argv) {
    if (argc == 0) return 1;

    stack* s = new_stack();
    char* str = argv[1];
    int len = strlen(str);

    // Eliminate trivial case
    if (len == 1) {
        printf("INVALID");
        return 1;
    }
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            push(str[i], s);
        } else if (str[i] == ')') {
            pop(s);
        }

    }
    if (s->length != 0) {
        printf("INVALID");
        return 1;
    }
    printf("VALID");
    return 0;
}
