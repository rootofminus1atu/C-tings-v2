#include <stdio.h>

int main() {
    void foo1 (int xval);
    void foo2 (int dummy);

    foo1(7);
    foo2(11);

    return 0;
}

void foo1 (int xval) {
    int x;
    x = xval;

    printf("x.address = 0x%x\nx.value = %d\n", &x, x);
}

void foo2(int dummy)
{
    int y;
    y = dummy;

    printf("y.address = 0x%x\ny.value = %d\n", &y, y);
}
