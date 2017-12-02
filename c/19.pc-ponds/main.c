#include <stdio.h>

/*
Input
The first line contains two integer m, n, representing the size of the map Frank gives to you.

The next m lines contain n characters, either '~' or '.', representing the status of position aij.

It is guaranteed that :

1 ≤ m, n ≤ 1000

Output
Please output the number of ponds on the map.

Sample Input
2 3
~.~
~..

Sample Output
2
*/

int main() {
    int m, n;
    scanf(" %d %d", &m, &n);

    char map[1000][1000];
    for (int i=0; i<m; i++) {
        for( int j=0; j<n; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    // dump map
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
