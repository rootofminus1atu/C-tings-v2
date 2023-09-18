#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;

struct Node {
    void *data;
    Node *next;
};

Node *NewNode(void *data, Node *next) {
    Node *new = malloc(sizeof(*new));
    new->data = data;
    new->next = next;
    return new;
}

typedef struct {
    Node *head;
} List;

void *CreateInt(int i) {
    void *ptr = malloc(sizeof(*ptr));
    *((int*)ptr) = i;
    return ptr;
}

int main() {
    printf("Hello, World!\n");

    Node *new = NewNode(CreateInt(5), NULL);

    printf("Thing in node: %d\n", *((int*)(new->data)));






    return 0;
}

