#include <stdio.h>
#include <stdbool.h>

struct Factory {
    char name[21];
    int a;
    int b;
};

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    struct Factory factories[500];
    for (int i=0; i<n; i++) {
        scanf("%s %d %d", factories[0].name, &factories[0].a, &factories[0].b);
    }

    // TODO analyze factories
    
}
