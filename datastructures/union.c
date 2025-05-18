#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 220.5;
    printf("data.f = %.2f\n", data.f);

    snprintf(data.str, sizeof(data.str), "Hello, World!");
    printf("data.str = %s\n", data.str);

    printf("\nUnion values after assignments:\n");
    printf("data.i = %d\n", data.i);
    printf("data.f = %.2f\n", data.f);
    printf("data.str = %s\n", data.str);

    return 0;
}
