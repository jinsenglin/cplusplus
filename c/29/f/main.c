#include <stdio.h>
#include <stdbool.h>
/*
struct Edge {
    int from;
    int to;
};*/

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int pool1[1000] = { 0 };
        int pool2[1000] = { 0 };
//        struct Edge edges[1000000];
        for (int j=0; j<m; j++) {
            int from, to;
            scanf("%d %d", &from, &to);
//            scanf("%d %d", &edges[j].from, &edges[j].to);

            // analyze TODO
        }

    }
}
