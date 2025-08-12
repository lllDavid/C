#include <immintrin.h>
#include <stdio.h>

int main(void) {
    float a[4] = {1.0, 2.0, 3.0, 4.0};
    float b[4] = {5.0, 6.0, 7.0, 8.0};
    float result[4];

    __m128 va = _mm_loadu_ps(a);
    __m128 vb = _mm_loadu_ps(b);
    __m128 vc = _mm_add_ps(va, vb);
    _mm_storeu_ps(result, vc);

    for (int i = 0; i < 4; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    return 0;
}