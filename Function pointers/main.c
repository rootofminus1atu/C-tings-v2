#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"

typedef int (*intTOint)(int);
typedef bool (*intTObool)(int);

int *map(int arr[], int size, intTOint func) {
    for (int i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
    return arr;
}

int *filter(int arr[], int size, intTObool func) {
    int counter = 0;
    int *newArr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        if (func(arr[i])) {
            newArr[counter] = arr[i];
            counter++;
        }
    }

    return newArr;
}



int add1(int num) {
    return num + 1;
}

int square(int num) {
    return num * num;
}

bool iseven(int num) {
    return num % 2 == 0 ? true : false;
}

void ListMap(List *lst, intTOint func) {
    for (Node *current = lst->head; current != NULL; current = current->next)
        current->value = func(current->value);
}

void PopNode(List *lst, Node *node) {
    Node *before = node->prev;
    Node *after = node->next;

    if (before == NULL && after == NULL) {
        lst->head = NULL;
        lst->tail = NULL;
    } else if (before == NULL) {
        after->prev = NULL;
        lst->head = after;
    } else if (after == NULL) {
        lst->tail = before;
        before->next = NULL;
    } else {
        after->prev = before;
        before->next = after;
    }

    free(node);
    lst->length--;
}

void ListFilter(List *lst, intTObool func) {
    Node *current = lst->head;
    Node *next;

    while (current != NULL) {
        next = current->next;

        if (!func(current->value))
            PopNode(lst, current);

        current = next;
    }
}

int main() {
    List *lst = NewList();
    AddRange(lst, 1, 3, 1);
    PrintList(lst);
    ListMap(lst, square);
    PrintList(lst);
    ListFilter(lst, iseven);
    PrintList(lst);

    int arr[] = {1, 2, 3};
    int *arred = map(arr, 3, add1);

    for (int i = 0; i < 3; i++) {
        printf("arr[%d] = %d\n", i, arred[i]);
    }


}
