#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

Node *NewNode(int value, Node *next, Node *prev) {
    Node *new = malloc(sizeof(*new));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = next;
    new->prev = prev;
    return new;
}


typedef struct {
    Node *head;
} DList;

DList *NewDList() {
    DList *lst = malloc(sizeof(*lst));
    if (lst == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    lst->head = NULL;
    return lst;
}


typedef struct {
    Node *head;
    Node *tail;
} Queue;

Queue *NewQueue() {
    Queue *q = malloc(sizeof(*q));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void Enqueue(Queue *q, int val) {
    Node *new;
    if (q->head == NULL) {
        new = NewNode(val, NULL, NULL);
        q->tail = new;
    } else {
        new = NewNode(val, q->head, NULL);
        q->head->prev = new;
    }
    q->head = new;
}

void Dequeue(Queue *q) {
    if (q->head == NULL) {
        printf("nobody in queue\n");
        return;
    }
    Node *tempOld = q->tail;
    q->tail = q->tail->prev;

    if (q->tail == NULL) {
        q->head = NULL;
    } else {
        q->tail->next = NULL;
    }

    free(tempOld);
}

void PrintQueue(Queue *q) {
    Node *current = q->head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
}

void DequeueAll(Queue *q) {
    while (q->head != NULL) {
        printf("Dequeueing %d\n", q->tail->value);
        Dequeue(q);
    }
    printf("Nothing left to dequeue\n");
}

void Push(DList *lst, int val) {
    Node *new;
    if (lst->head == NULL) {
        new = NewNode(val, NULL, NULL);
    } else {
        new = NewNode(val, lst->head, NULL);
        lst->head->prev = new;
    }
    lst->head = new;
}



int main() {
    Queue *q = NewQueue();
    Enqueue(q, 4);
    PrintQueue(q);
    Enqueue(q, 5);
    PrintQueue(q);
    Enqueue(q, 6);
    PrintQueue(q);

    DequeueAll(q);
    PrintQueue(q);



    return 0;
}
