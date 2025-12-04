#include <stdio.h>

int times_summed = 0;

int vexc_sum(int left, int right) {
    printf("Summing: %d, %d\n", left, right);
    times_summed++;
    printf("Times summed: %d\n", times_summed);

    return left + right;
}
