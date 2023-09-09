#include <stdio.h>
#include <stdlib.h>


int main() {
    void swap(int *pa, int *pb);

    int a = 4;
    int b = 5;

    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);


    printf("how long array: ");
    int len; scanf("%d", &len);

    int *arr = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", arr+i);
    }

    printf("arr = [ ");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i != len - 1) {
            printf(", ");
        }
    }
    printf(" ]");



    free(arr);



    return 0;
}

void swap(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

