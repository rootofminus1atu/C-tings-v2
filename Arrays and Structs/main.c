#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main() {
    void displayArray(int arr[], int size);
    void print2x2Mat(float arr[][2]);

    int nums[6] = {4, 3, 2, 5, 1, 8};
    displayArray(nums, ARRAY_SIZE(nums));

    int grades[2][2] = {1,2,3,4};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("grades[%d][%d]=%d\n", i, j, grades[i][j]);
        }
    }

    float mat[2][2] = {1, 2, 3, 4};
    print2x2Mat(mat);


    typedef struct {
        int x;
        int y;
        int z;
    } Point3D;

    Point3D p1;
    p1.x = 0;
    p1.y = 0;
    p1.z = 0;

    Point3D p2 = {.x=1, .y=1, .z=1};

    printf("p1 = (%d, %d, %d)\np2 = (%d, %d, %d)\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);


    Point3D somePoints[5];
    for (int i = 0; i < 5; i++) {
        somePoints[i].x = i;
        somePoints[i].y = i + 1;
        somePoints[i].z = i + 2;
    }

    for (int i = 0; i < 5; i++) {
        printf("somePoints[%d] = (%d, %d, %d)\n", i, somePoints[i].x, somePoints[i].y, somePoints[i].z);
    }

    return 0;
}

void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i != size - 1)
            printf("%d, ", arr[i]);
        else
            printf("%d", arr[i]);
    }
    printf("]\n");
}

void print2x2Mat(float arr[][2]) {
    for (int i = 0; i < 2; i++) {
        printf("[ ");
        for (int j = 0; j < 2; j++) {
            printf("%f ", arr[i][j]);
        }
        printf("]\n");
    }
}

