#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    void *next;
} Node;

Node *NewNode(int value, Node *next) {
    Node *new = malloc(sizeof(*new));
    new->value = value;
    new->next = next;
    return new;
}


typedef struct {
    Node *head;
} List;

List NewList() {
    List lst = { .head = NULL };
    return lst;
}

List *NewHeapList() {
    List *lst = malloc(sizeof(List));
    lst->head = NULL;
    return lst;
}

void FreeList(List *lst) {
    Node *current = lst->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    lst->head = NULL;
}

void PrintList(List *lst) {
    Node *temp = lst->head;

    printf("[ ");

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("]\n");
}

void Push(List *lst, int val) {
    Node *new = NewNode(val, lst->head);
    lst->head = new;
}

void Pull(List *lst) {
    if (lst->head == NULL) {
        return;
    }
    Node *firstNode = lst->head;
    lst->head = lst->head->next;
    free(firstNode);
}


int ListLen(List *lst) {
    int count = 0;
    Node *current = lst->head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int GetAtIndex(List *lst, int index) {
    Node *temp = lst->head;
    // int len = ListLen(lst);

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    int val = temp->value;

    return val;
}

void SetAtIndex(List *lst, int index, int value) {
    Node *temp = lst->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    temp->value = value;
}

void Reverse(List *lst) {
    if (lst->head == NULL) {
        return;
    }

    Node *overseer = lst->head;
    Node *reverser = NULL;
    Node *nextNode = NULL;

    while (overseer != NULL) {
        nextNode = overseer->next;  // Store the next node
        overseer->next = reverser;  // Update next pointer to the previous node
        reverser = overseer;  // Move the pointers forward
        overseer = nextNode;  // Move to the next node
    }
    lst->head = reverser;
}

int main() {
    List *woah = NewHeapList();
    Push(woah, 1);
    Push(woah, 2);
    Push(woah, 3);
    PrintList(woah);
    Reverse(woah);
    PrintList(woah);




    List lst = NewList();

    Push(&lst, 6);
    Push(&lst, 7);
    Push(&lst, 8);
    Push(&lst, 9);
    PrintList(&lst);

    printf("lst is %d long\n", ListLen(&lst));
    PrintList(&lst);

    int index = 2;
    printf("lst[%d] = %d\n", index, GetAtIndex(&lst, index));
    PrintList(&lst);

    FreeList(&lst);


    List *lst2 = NewHeapList();

    Push(lst2, 9);
    PrintList(lst2);
    Push(lst2, 10);
    PrintList(lst2);

    printf("%d\n", (*lst2).head->value);

    Pull(lst2);
    PrintList(lst2);
    Pull(lst2);
    PrintList(lst2);

    FreeList(lst2);

    return 0;
}
