#include <stdio.h>

typedef struct _Factory {
    char name[21];  // factory name
//    int a;          // profit of producing car A
//    int b;          // profit of producing car B
    int x;          // x = a-b
} Factory;

int main() {
    int n;
    int x;
    int y;
    scanf("%d %d %d", &n, &x, &y);

    Factory factories[n];
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%s %d %d", factories[i].name, &a, &b);
        factories[i].x = a-b;
    }
}
