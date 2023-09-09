#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Node init
 *
 */

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

Node *NewNode(int value, Node *next, Node *prev) {
    Node *new = malloc(sizeof(*new));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation for Node failed\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = next;
    new->prev = prev;
    return new;
}

/*
 *
 * Basic init and print functions
 *
 */

typedef struct {
    Node *head;
    Node *tail;
    int length;
} List;

List *NewList() {
    List *lst = malloc(sizeof(*lst));
    if (lst == NULL) {
        fprintf(stderr, "Memory allocation for List failed\n");
        exit(EXIT_FAILURE);
    }
    lst->head = NULL;
    lst->tail = NULL;
    lst->length = 0;
    return lst;
}

void PrintList(List *lst) {
    Node *current;

    printf("[ ");

    for (current = lst->head; current != NULL; current = current->next) {
        printf("%d ", current->value);
    }

    printf("]\n");
}

/*
 *
 * Functions for adding/removing elements from the front/back
 *
 */

void Push(List *lst, int val) {
    Node *new;

    if (lst->head == NULL) {
        new = NewNode(val, NULL, NULL);
        lst->head = new;
        lst->tail = new;
    } else {
        new = NewNode(val, lst->head, NULL);
        lst->head = new;
        lst->head->next->prev = new;
    }

    lst->length++;
}

void Pull(List *lst) {
    if (lst->head == NULL)
        return;

    Node *first = lst->head;
    Node *second = lst->head->next;

    if (second == NULL) {
        lst->tail = NULL;
    } else {
        second->prev = NULL;
    }
    free(first);
    lst->head = second;

    lst->length--;
}

void Append(List *lst, int val) {
    Node *new;

    if(lst->tail == NULL) {
        new = NewNode(val, NULL, NULL);
        lst->head = new;
        lst->tail = new;
    } else {
        new = NewNode(val, NULL, lst->tail);
        lst->tail = new;
        lst->tail->prev->next = new;
    }

    lst->length++;
}

void Deappend(List *lst) {
    if (lst->tail == NULL)
        return;

    Node *first = lst->tail;
    Node *second = lst->tail->prev;

    if (second == NULL) {
        lst->head = NULL;
    } else {
        second->next = NULL;
    }
    free(first);
    lst->tail = second;

    lst->length--;
}

void Erase(List *lst) {
    while (lst->head != NULL) {
        printf("Killing %d\n", lst->tail->value);
        Deappend(lst);
    }
    printf("Nothing left to kill\n");
}

void Free(List *lst) {
    Erase(lst);
    free(lst);
}

/*
 *
 * Index based functions
 *
 */

void VerifyIndex(List *lst, int index) {
    if (index < 0 || index >= lst->length) {
        fprintf(stderr, "index %d is out of bounds (list length: %d)\n", index, lst->length);
        exit(EXIT_FAILURE);
    }
}

Node *IthNode(List *lst, int index) {
    VerifyIndex(lst, index);

    // possibly code that relies on the length through which you can lookup the last element faster

    Node *temp = lst->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp;
}

int GetValueAtIndex(List *lst, int index) {
    Node *target = IthNode(lst, index);

    return target->value;
}

void SetValueAtIndex(List *lst, int index, int val) {
    Node *target = IthNode(lst, index);

    target->value = val;
}

void PopAtIndex(List *lst, int index) {
    Node *target = IthNode(lst, index);
    Node *before = target->prev;
    Node *after = target->next;

    if (before == NULL && after == NULL) {
        lst->tail = NULL;
        lst->head = NULL;
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

    printf("Freeing lst[%d] = %d\n", index, target->value);
    free(target);

    lst->length--;  // DO NOT forget to include this
    // would be nice if I could
}

// alternate version, relying on the length rather than the neighbors

void PopAtIndex2(List *lst, int index) {
    if (index == 0) {
        Pull(lst);
        return;
    } else if (index == lst->length - 1) {
        Deappend(lst);
        return;
    }

    Node *target = IthNode(lst, index);

    target->next->prev = target->prev;
    target->prev->next = target->next;

    free(target);

    lst->length--;  // DO NOT forget to include this
}

/*
 *
 * reversal, shuffle and other misc functions
 *
 */

void SwapPointers(Node **ptr1, Node **ptr2) {
    Node *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void Reverse(List *lst) {
    for (Node *current = lst->head; current != NULL; current = current->prev) {
        SwapPointers(&current->prev, &current->next);
    }
    SwapPointers(&lst->head, &lst->tail);
}

void AddRange(List *lst, int start, int end, int step) {
    if (step == 0) {
        fprintf(stderr, "Cannot generate range with step %d", step);
        exit(EXIT_FAILURE);
    }

    int direction = (start < end) ? 1 : -1;

    if (direction * step <= 0) {
        fprintf(stderr, "Invalid step value %d for the given range (%d to %d)", step, start, end);
        exit(EXIT_FAILURE);
    }

    for (int i = start; (direction > 0) ? (i < end) : (i > end); i += step) {
        Append(lst, i);
    }
}
