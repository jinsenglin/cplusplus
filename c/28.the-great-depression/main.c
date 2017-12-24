#include <stdio.h>

typedef struct _Factory {
    char name[21];  // factory name
//    int a;          // profit of producing car A
//    int b;          // profit of producing car B
    int x;          // x = a-b
} Factory;

int main() {
    // init n, x, y
    int n;
    int x;
    int y;
    scanf("%d %d %d", &n, &x, &y);

    // init factories
    Factory factories[n];
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%s %d %d", factories[i].name, &a, &b);
        factories[i].x = a-b;
    }

    // sort factories by x
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (factories[j].x < factories[j+1].x) {
                // swap
                Factory tmp = factories[j];
                factories[j] = factories[j+1];
                factories[j+1] = tmp;
            }
        }
    }

    // sort factories by name
    for (int i=0; i<x-1; i++) {
        for (int j=0; j<x-1; j++) {
            if (factories[j].name[0] > factories[j+1].name[0]) {
                // swap
                Factory tmp = factories[j];
                factories[j] = factories[j+1];
                factories[j+1] = tmp;
            }
        }
    }

    // print top x
    for (int i=0; i<x; i++) printf("%s\n", factories[i].name);
}
