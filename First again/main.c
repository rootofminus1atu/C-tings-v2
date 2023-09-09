#include <stdio.h>
/* #include <math.h> */

int main() {
    void xml();
    double circArea(double rad);
    double fToC(double fahr);
    int summation(int n);
    void determineSign(int n);
    void tellParityOfRange(int n);
    void xmasTree(int max);
    void xmasTree2(int max);
    int Fibonacci(int n);

    xml();

    double r = 10;
    printf("The area of a circle with radius %f is %.2f\n", r, circArea(r));

    double fah = 27;
    printf("%f degrees F is %f degrees C\n", fah, fToC(fah));

    int upper = 100;
    printf("I added all numbers up to %d and got %d\n", upper, summation(upper));

    determineSign(0);

    tellParityOfRange(5);

    xmasTree(6);

    int n = 10;
    int Fn = Fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, Fn);





    return 0;
}

void xml() {
    char x = 'X', m = 'M', l = 'L';
    printf("Look %c%c%c\n", l, m, x);
}

double circArea(double radius) {
    return 3.14 * radius * radius;
}

double fToC(double fahr) {
    return (fahr - 32)/1.8;
}

int summation(int num) {
    int sum = 0;

    for (int i = 0; i <= num; i++)
        sum += i;

    return sum;
}

void determineSign(int n) {
    if (n < 0)
        printf("%d is negative\n", n);
    else if (n == 0)
        printf("%d is neither positive nor negative, it's %d\n", n, n);
    else
        printf("%d is positive\n", n);
}

void tellParityOfRange(int n) {
    for (int i = 1; i <= n; i++)
        (i % 2) ? printf("%d is odd\n", i) : printf("%d is even\n", i);
}

void xmasTree(int max) {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < 2 * max - 1; j++) {
            if (j >= max - 1 - i && j <= max - 1 + i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void xmasTree2(int max) {
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < max - i; j++) {
            printf(" ");
        }
        for (int j = max - i; j < max - i + 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int Fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}
