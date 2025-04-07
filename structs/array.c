#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("The elements of the array are:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
