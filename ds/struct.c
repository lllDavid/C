#include <stdio.h>

struct Person {
    char name[50];
    int age;
    char address[100];
};

int main() {
    struct Person person1 = {"John Doe", 30, "123 Elm St"};

    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address: %s\n", person1.address);

    return 0;
}
