#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} Student;

Student StudentInit(char *name, int age) {
    Student student;

    student.age = age;
    char *nameStr = name;
    student.name = malloc((strlen(nameStr) + 1) * sizeof(char));
    strcpy(student.name, nameStr);

    return student;
}

void StudentInfo(Student student) {
    printf("%s aged %d\n", student.name, student.age);
}

char *readString(char prompt[]);

int main() {
    printf("how many students ");
    int amount; scanf("%d", &amount);
    getchar();  // clear the newline character from the input buffer

    Student *students = malloc(amount * sizeof(Student));

    for (int i = 0; i < amount; i++) {
        char *name = readString("Input name: ");
        printf("Input age: ");
        int age; scanf("%d", &age);
        getchar();

        Student student = StudentInit(name, age);
        students[i] = student;
    }

    for (int i = 0; i < amount; i++) {
        StudentInfo(students[i]);
    }


    // free allocated memory
    for (int i = 0; i < amount; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}

char *readString(char prompt[]) {
    char *input = malloc(sizeof(char));
    char singleChar;
    int len = 0;

    printf("%s", prompt);

    while (scanf("%c", &singleChar) == 1) {
        if (singleChar == '\n')
            break;

        len++;
        input = realloc(input, len + 2);
        input[len - 1] = singleChar;
    }

    input[len] = '\0';

    return input;
}
