#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

typedef struct {
    Node *head;
} List;

List InitList() {
    List lst;
    lst.head = NULL;

    return lst;
}

Node *InitNode(int value, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

void KillNode(Node *target) {
    if (target != NULL && target->next == NULL) {
        free(target);
    } else {
        printf("Can't free some node...");
    }
}

void Append(List *lst, int val) {
    Node *newNode = InitNode(val, NULL);
    printf("Created a new node\n");

    Node *current = lst->head;

    if (current == NULL) {
        printf("List head was empty\n");
        lst->head = newNode;
    } else {
        printf("List head was NOT empty\n");

        while (current->next != NULL) {
            printf("Went 1 step deeper\n");
            current = current->next;
        }

        printf("Found the end\n");
        current->next = newNode;
    }

    // free(current);
    // WHY DOES THIS RESULT IN AN INFINITE LOOP

    printf("Exited\n");
}

void PrintList(List lst) {
    printf("[");

    if (lst.head != NULL) {
        Node *current = lst.head;

        while (current != NULL) {
            printf(" %d ", current->value);
            current = current->next;
        }
    }

    printf("]\n");
}

int main() {
    printf("Hello, World!\n");

    List lst = InitList();

    Append(&lst, 4);
    printf("%d\n", lst.head->value);
    Append(&lst, 5);
    printf("%d\n", lst.head->next->value);

    PrintList(lst);



    List lst2 = InitList();
    PrintList(lst2);

    return 0;
}
