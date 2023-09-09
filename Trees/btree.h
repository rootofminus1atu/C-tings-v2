//
// Created by Luke on 08/09/2023.
//

#ifndef TREES_BTREE_H
#define TREES_BTREE_H

#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void MallocCheck(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void SwapPointers(void **p1, void **p2) {
    void *temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}



typedef struct Node Node;

struct Node {
    int value;
    Node *left;
    Node *right;
};

Node *NewNode(int value, Node *left, Node *right) {
    Node *new = malloc(sizeof(*new));
    MallocCheck(new);

    new->value = value;
    new->left = left;
    new->right = right;

    return new;
}


typedef struct {
    Node *root;
    int metadata;
} BTree;



BTree *NewBTree() {
    BTree *new = malloc(sizeof(*new));
    MallocCheck(new);

    new->root = NULL;
    new->metadata = 0;

    return new;
}

void PrintSubtree(Node *node);
void PrintSubtreeV2(Node *node2);

void PrintTree(BTree *tree) {
    PrintSubtree(tree->root);
    printf("\n");
    PrintSubtreeV2(tree->root);
    printf("\n");
}

void PrintSubtree(Node *node) {
    if (node == NULL) {
        printf("()");
        return;
    }

    printf("%d", node->value);

    if (node->left != NULL) {
        printf("(");
        PrintSubtree(node->left);
        printf(")");
    }

    if (node->right != NULL) {
        printf("(");
        PrintSubtree(node->right);
        printf(")");
    }
}

void PrintSubtreeV2(Node *node) {
    if (node == NULL) {
        printf("-");
        return;
    }

    if (node->left == NULL && node->right == NULL) {
        printf("%d", node->value);
        return;
    }

    printf("%d", node->value);

    printf("(");
    PrintSubtreeV2(node->left);
    printf(")");

    printf("(");
    PrintSubtreeV2(node->right);
    printf(")");
}



bool CheckIfInBSubTree(Node *node, int val) {
    if (node == NULL) {
        return false;
    }

    if (node->value == val) {
        return true;
    }

    bool foundInLeftSubtree = CheckIfInBSubTree(node->left, val);
    bool foundInRightSubtree = CheckIfInBSubTree(node->right, val);

    return foundInLeftSubtree || foundInRightSubtree;
}

bool CheckIfInBTree(BTree *tree, int val) {
    return CheckIfInBSubTree(tree->root, val);
}




void ReverseBSubTree(Node *node) {
    if (node == NULL) {
        return;
    }

    SwapPointers((void **) &node->left, (void **) &node->right);

    // go down branches and recurse
    ReverseBSubTree(node->left);
    ReverseBSubTree(node->right);
}

void ReverseBTree(BTree *tree) {
    ReverseBSubTree(tree->root);
}




int GetBSubTreeDepth(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int leftDepth = GetBSubTreeDepth(node->left);
    int rightDepth = GetBSubTreeDepth(node->right);

    int depth = MAX(leftDepth, rightDepth);

    return depth + 1;
}

int GetDepth(BTree *tree) {
    return GetBSubTreeDepth(tree->root);
}



void FreeBSubTree(Node *node) {
    if (node == NULL) {
        return;
    }

    FreeBSubTree(node->left);
    FreeBSubTree(node->right);

    printf("Freeing %d\n", node->value);
    free(node);
}

void CutDown(BTree *tree) {
    FreeBSubTree(tree->root);
    free(tree);
}







#endif //TREES_BTREE_H
