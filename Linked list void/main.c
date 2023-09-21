#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

List *NewList() {
    List *new = malloc(sizeof(*new));
    new->head = NULL;
    return new;
}


void Prepend(List *list, void *data) {
    Node *new = NewNode(data, list->head);
    list->head = new;
}





void PrintInt(void *data) {
    int *value = (int *)data;
    printf("%d", *value);
}

void PrintString(void *data) {
    char *value  = (char *)data;
    printf("%s", value);
}



void PrintList(List *list, void (*printFn)(void *)) {
    Node *curr = list->head;

    printf("[ ");
    while (curr != NULL) {
        printFn(curr->data);
        printf(" ");
        curr = curr->next;
    }
    printf("]\n");
}



void *CreateInt(int i) {
    void *ptr = malloc(sizeof(*ptr));
    *((int*)ptr) = i;
    return ptr;
}

int main() {
    printf("Hello, World!\n");

    char sentence[] = "Hello there brae :3";
    int len = strlen(sentence);

    // go from back
    // when hit space
    // propagate forward
    // keep track of the length of the word

    int wordStart;
    int wordEnd = len;

    for (int i = len - 1; i >= 0; i--) {

        // check if we hit a space (or we're at the start)
        if (sentence[i] == ' ' || i == 0) {
            wordStart = (i == 0) ? 0 : i + 1;

            // print stuff forward on
            for (int j = wordStart; j < wordEnd; j++) {
                char letter = sentence[j];
                printf("%c", letter);
            }
            printf(" ");

            wordEnd = i;
        }
    }

    printf("\n\n");






    List *myList = NewList();

    // Add some elements to the list using Prepend
    int num1 = 42;
    int num2 = 99;
    int num3 = 73;

    Prepend(myList, &num1);
    Prepend(myList, &num2);
    Prepend(myList, &num3);

    int elems[] = {1, 2, 3};


    PrintList(myList, PrintInt);




    return 0;
}

