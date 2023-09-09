#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main() {
    printf("Hello, World!\n");

    BTree *tree = NewBTree();

    Node *base = NewNode(
            2,
            NewNode(
                    5,
                    NULL,
                    NULL
                    ),
            NewNode(
                    3,
                    NewNode(1, NULL, NULL),
                    NULL
                    )
    );
    tree->root = base;

    PrintTree(tree);

    int val = 0;
    bool verdict = CheckIfInBTree(tree, val);
    printf("%d in tree? %s\n", val, verdict ? "true" : "false");

    ReverseBTree(tree);
    PrintTree(tree);

    int val2 = 3;
    bool verdict2 = CheckIfInBTree(tree, val2);
    printf("%d in tree? %s\n", val2, verdict2 ? "true" : "false");



    int depth = GetDepth(tree);
    printf("The depth is: %d", depth);





    CutDown(tree);



    BTree *fakeTree = NewBTree();
    printf("The depth of this fake tree is %d", GetBSubTreeDepth(fakeTree->root));

    return 0;
}

