#include <stdio.h>
#include <stdbool.h>

int main() {
    int T = 0;
    scanf("%d", &T);

    for (int t=0; t<T; t++) {
        int n = 2;
        scanf("%d", &n);

        float A[n][n];
        int X[n];
        int p;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%f", &A[i][j]);
            }
        }
        for (int i=0; i<n; i++) {
            scanf("%d", &X[i]);
        }
        scanf("%d", &p);

        // next X
        float MOVE[n][n];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                MOVE[i][j] = A[i][j] * X[j];
            }
        }
        for (int i=0; i<n; i++) {
            X[i] = 0;
            for (int j=0; j<n; j++) {
                X[i] += MOVE[i][j];
            }
        }

        // [ DEBUG ] print X
        for (int i=0; i<n; i++) {
            printf("%d ", X[i]);
        }
    }
}
