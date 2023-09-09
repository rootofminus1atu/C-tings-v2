#include <stdio.h>
#include <stdlib.h>

int getLen(char str[]);
int getLen2(char *str);
int freqOfCharIn(char str[], char c);
char *copy(char str[]);
char *concat(char str1[], char str2[]);
char *substr(char str[], int from, int to);
int countWords(char text[]);
char **intoWords(char text[]);

int main() {
    char str[] = "helloo";
    char target = 'l';

    printf("%s is %d long\n", str, getLen(str));
    printf("%s is %d long\n", str, getLen2(str));
    printf("%c appears %d time(s) in %s\n", target, freqOfCharIn(str, target), str);

    printf("%s\n", str);
    str[0] = 'j';
    printf("now we copy %s\n", str);
    char *strCopy = copy(str);
    strCopy[0] = 'h';
    printf("str = %s, copy = %s\n", str, strCopy);

    free(strCopy);


    char str1[] = "awe";
    char str2[] = "some";
    char *sum = concat(str1, str2);
    printf("%s + %s = %s\n", str1, str2, sum);

    free(sum);


    char word[] = "longwordvery";
    int from = 4;
    int to = 8;
    char *sub = substr(word, from, to);
    printf("substring from %d to %d: %s\n", from, to, sub);

    free(sub);



    // works without duplicated spaces
    char text[] = "Number 15 Burger";
    char **wordList = intoWords(text);

    for (int i = 0; wordList[i] != NULL; i++) {
        printf("Word %d: %s\n", i, wordList[i]);
        free(wordList[i]);
    }

    free(wordList);


    return 0;
}

char **intoWords(char text[]) {
    int wordCount = countWords(text);

    // +1 for a NULL word at the end
    char **wordList = malloc((wordCount + 1) * sizeof(char*));

    int start = 0;
    int end = 0;
    int wlIndex = 0;  // word list index

    for (int i = 0; i <= getLen(text); i++) {
        if (text[i] == ' ' || text[i] == '\0') {
            end = i;

            char *foundWord = substr(text, start, end);
            wordList[wlIndex] = foundWord;
            wlIndex++;

            start = i + 1;
        }
    }

    wordList[wlIndex] = NULL;

    return wordList;
}

int countWords(char text[]) {
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ')
            count++;
    }

    return count;
}

char *substr(char str[], int from, int to) {
    int len = to - from;
    char *newWord = malloc((len + 1) * sizeof(char));

    if (newWord != NULL) {
        for (int i = 0; i < len; i++) {
            newWord[i] = str[from + i];
        }
        newWord[len] = '\0';
    }

    return newWord;
}

char *concat(char str1[], char str2[]) {
    int len1 = getLen(str1);
    int len2 = getLen(str2);
    char *joined = malloc((len1 + len2 + 1) * sizeof(char));

    if (joined != NULL) {
        int index = 0;

        for (int i = 0; i < len1; i++) {
            joined[index] = str1[i];
            index++;
        }
        for (int i = 0; i < len2; i++) {
            joined[index] = str2[i];
            index++;
        }

        joined[index] = '\0';
    }

    return joined;
}

char *copy(char str[]) {
    int length = getLen(str);
    char *copyStr = malloc((length + 1) * sizeof(char));

    if (copyStr != NULL) {
        // watch this    vvvv    yes <= because null terminator at the end
        for (int i = 0; i <= length; i++) {
            copyStr[i] = str[i];  // copy each character
        }
    }

    return copyStr;
}

int freqOfCharIn(char str[], char c) {
    int count = 0;

    for (int i = 0; i < getLen(str); i++) {
        if (str[i] == c)
            count++;
    }

    return count;
}

int getLen(char str[]) {
    int i = 0;

    while (str[i] != '\0' && i < 100) {
        i++;
    }

    return i;
}

int getLen2(char *str) {
    int i = 0;

    while (*(str + i) != '\0' && i < 100) {
        i++;
    }

    return i;
}

int getLen3(char *str) {
    int i;

    for (i = 0; *(str + i) != '\0' ; i++) {}

    return i;
}
