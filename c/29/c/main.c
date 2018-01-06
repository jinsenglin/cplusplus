#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Record {
    char name[21];
    int score;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Record records[100000];
    for (int i=0; i<n; i++) {
        scanf("%s %d", records[i].name, &records[i].score);
    }

}
