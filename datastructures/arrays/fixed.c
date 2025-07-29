#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printf("1D: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("2D: ");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("Char array: %s\n", str);

    int a = 100, b = 200, c = 300;
    int *ptrArr[3] = {&a, &b, &c};
    printf("Array of pointers: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", *ptrArr[i]);
    }
    printf("\n");

    return 0;
}