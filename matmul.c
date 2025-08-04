#include <stdio.h>

#define MAX 10

void matmul(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX], r1, c1, r2, c2;
    printf("Enter rows and columns for first matrix: ");
    scanf_s("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf_s("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matmul is not possible.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf_s("%d", &first[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf_s("%d", &second[i][j]);
        }
    }

    matmul(first, second, result, r1, c1, r2, c2);

    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}