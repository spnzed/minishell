#include <stdio.h>
#include <unistd.h>

int my_getchar() {
    char c;
    if (read(0, &c, 1) == 1) {  // Read a character from stdin
        return (unsigned char)c;  // Convert to int to match getchar's return type
    } else {
        return EOF;  // End of file or error
    }
}

int main() {
    int c;

    while ((c = my_getchar()) != EOF) {
        putchar(c);  // Echo the character
    }

    return 0;
}
/*
int main() {
    int c;

    printf("Enter a character: ");
    c = my_getchar();

    printf("You entered: ");

    if (c != EOF) {
        putchar(c);
    } else {
        printf("End of file encountered.\n");
    }

    return 0;
}*/