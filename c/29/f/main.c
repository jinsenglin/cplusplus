#include <stdio.h>
#include <stdbool.h>

struct Edge {
    int from;
    int to;
};

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        struct Edge edges[1000000];
        for (int j=0; j<m; j++) {
            scanf("%d %d", &edges[j].from, &edges[j].to);
        }
    }
}
