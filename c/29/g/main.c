#include <stdio.h>
#include <stdbool.h>

int last_bit(int *num) {
    int one_or_zero = *num - (*num >> 1)*2;
    *num = *num >> 1;

    //printf("DEBUG: %d\n", one_or_zero);
    return one_or_zero;
}

int main() {
    int n;
    scanf("%d", &n);

    int bits[20] = { 0 };
    int a[100000] = { 0 };
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);

        int ai = a[i];
        int pos = 0;
        while (ai > 0) {
            if (last_bit(&ai) == 1) bits[pos]++;
            else bits[pos]--;

            pos++;
        }

    }

    // DEBUG: dump bits
    for (int i=19; i>-1; i--) printf("%d ", bits[i]);
}
