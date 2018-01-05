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
        for (int pos=19; pos>-1; pos--) {
            if (last_bit(&ai) == 1) bits[pos]++;
            else bits[pos]--;
        }
    }

    // DEBUG: dump bits
    for (int pos=0; pos<20; pos++) printf("%d ", bits[pos]);
}
