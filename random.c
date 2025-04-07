#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    srand(time(NULL));

    int i;
    for(i = 0; i < 10; i++) {
        int randomNum = getRandom(1, 100);
        printf("%d ", randomNum);
    }
    
    return 0;
}