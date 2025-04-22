#include <math.h>

int jumpSearch(int arr[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[fmin(step, size) - 1] < key) {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }

    for (int i = prev; i < fmin(step, size); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}
