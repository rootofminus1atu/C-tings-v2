#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_INT 0
#define DEFAULT_CAP 4
#define GROWTH_FACTOR 2

typedef int (*intTOint)(int);
typedef bool (*intTObool)(int);

typedef struct {
    int *data;
    int length;
    int capacity;
} Array;

Array *NewArray() {
    Array *arr = malloc(sizeof(*arr));
    arr->data = malloc(DEFAULT_CAP * sizeof(arr->data));
    arr->length = 0;
    arr->capacity = DEFAULT_CAP;
    return arr;
}

void MutableMap(Array *arr, intTOint func) {
    for (int i = 0; i < arr->length; i++) {
        arr->data[i] = func(arr->data[i]);
    }
}

Array *ArrayCopy(Array *arr) {
    Array *new = malloc(sizeof(*new));
    new->data = malloc(arr->capacity * sizeof(arr->data));
    new->length = arr->length;
    new->capacity = arr->capacity;

    for (int i = 0; i < arr->length; i++) {
        new->data[i] = arr->data[i];
    }

    return new;
}

int print_val(int n) {
    printf("%d ", n);
    return n;
}

void PrintArray(Array *arr) {
    printf("[ ");
    MutableMap(arr, print_val);
    printf("]");
}

void ArrayInfo(Array *arr) {
    PrintArray(arr);
    printf(" (length = %d, capacity = %d)\n", arr->length, arr->capacity);
}

void FreeArray(Array *arr) {
    free(arr->data);
    free(arr);
}



void Resize(Array *arr, int new_cap) {
    int *new_data = realloc(arr->data, new_cap * sizeof(arr->data));

    if (new_data == NULL) {
        fprintf(stderr, "Failed to allocate memory to resize the array.\n");
        exit(1);
    }

    arr->data = new_data;
    arr->capacity = new_cap;
}

void ManageCapacity(Array *arr) {
    if (arr->length >= arr->capacity) {
        int new_cap = arr->capacity * GROWTH_FACTOR;
        Resize(arr, new_cap);
    } else if (arr->length <= arr->capacity / GROWTH_FACTOR && arr->capacity > DEFAULT_CAP) {
        int new_cap = arr->capacity / GROWTH_FACTOR;
        Resize(arr, new_cap);
    }
}

void Append(Array *arr, int n) {
    ManageCapacity(arr);

    arr->data[arr->length] = n;
    arr->length++;
}

void DeAppend(Array *arr) {
    if (arr->length == 0) {
        printf("You can't take away elements from an empty array.\n");
        return;
    }

    arr->data[arr->length - 1] = DEFAULT_INT;
    arr->length--;

    ManageCapacity(arr);
}

void IndexCheck(Array *arr, int index) {
    if (index < 0 || index >= arr->length) {
        fprintf(stderr, "Invalid index: %d (list length: %d\n", index, arr->length);
        exit(1);
    }
}

int Get(Array *arr, int index) {
    IndexCheck(arr, index);
    return arr->data[index];
}

void Set(Array *arr, int index, int val) {
    IndexCheck(arr, index);
    arr->data[index] = val;
}

void PopAtIndex(Array *arr, int index) {
    IndexCheck(arr, index);

    for (int i = index; i < arr->length - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
    ManageCapacity(arr);
}






Array *Map(Array *arr, intTOint func) {
    Array *new = NewArray();

    for (int i = 0; i < arr->length; i++) {
        Append(new, func(arr->data[i]));
    }

    return new;
}

Array *Map2(Array *arr, intTOint func) {
    Array *new = ArrayCopy(arr);

    for (int i = 0; i < arr->length; i++) {
        Set(new, i, func(arr->data[i]));
    }

    return new;
}

Array *Filter(Array *arr, intTObool func) {
    Array *new = NewArray();

    for (int i = 0; i < arr->length; i++) {
        if (func(arr->data[i])) {
            Append(new, arr->data[i]);
        }
    }

    return new;
}

void MutableFilter(Array *arr, intTObool func) {
    for (int i = 0; i < arr->length; i++) {
        if (!func(arr->data[i])) {
            PopAtIndex(arr, i);
            i--;
        }
    }
}

int add1(int n) {
    return n + 1;
}

bool iseven(int n) {
    return n % 2 == 0;
}


#define PRINTARR(arr) PrintStupidArray(arr, sizeof(arr)/sizeof(int))

void PrintStupidArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main() {
    int stupid[] = {1, 2, 3, 4, 5};
    PRINTARR(stupid);

    Array *arr = NewArray();
    Append(arr, 5);
    Append(arr, 6);
    Append(arr, 8);
    Append(arr, 7);
    Append(arr, 7);
    Append(arr, 10);
    Append(arr, 10);
    Append(arr, 10);
    Append(arr, 10);
    Append(arr, 12);
    Append(arr, 13);

    MutableFilter(arr, iseven);

    ArrayInfo(arr);

    FreeArray(arr);

    return 0;
}
