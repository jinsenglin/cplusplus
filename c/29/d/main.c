#include <stdio.h>
#include <stdbool.h>

long long int cal_determinant(int a[8][8], int n) {
    if (n == 2) {
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }
    else {
        // recursive TODO
        return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[8][8] = { 0 };
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    long long int ans = cal_determinant(a, n);
    printf("%lld\n", ans);
}
