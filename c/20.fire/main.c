#include <stdio.h>
#include <stdbool.h>

/*
Input
The first line contains two integer m, n, representing the size of the map eccioa gives to you.

The next m lines contain n characters, either 'e', '.', '^', '~', representing the status of position aij.

It is guaranteed that :

1 ≤ m, n ≤ 1000

Output
If eccioa can stay alive, please print "Alive!", otherwise please print "Dead!".

Sample Input
3 4
~~..
^^^.
e...

Sample Output
Alive!
*/

char map[1000][1000];
short y_max, x_max;

bool alive(short x, short y, char d) {
    /*
        (x, y) -> (x, y-1) means that go north
        (x, y) -> (x, y+1) means that go south
        (x, y) -> (x-1, y) means that go west
        (x, y) -> (x+1, y) means that go east
    */

    if ( x == -1 || y == -1 || x == x_max || y == y_max ) return false;
    else { 
        char c = map[y][x];

        if ( c == 'e' ) return alive(x, y-1, 'n') || alive(x, y+1, 's') || alive(x-1, y, 'w') || alive(x+1, y, 'e');
        else if ( c == '^' ) return false;
        else if ( c == '~') return true;
        else { // i.e., c == '.'
            if ( d == 'n' ) return alive(x, y-1, 'n') || alive(x-1, y, 'w') || alive(x+1, y, 'e');
            else if ( d == 's' ) return alive(x, y+1, 's') || alive(x-1, y, 'w') || alive(x+1, y, 'e');
            else if ( d == 'w' ) return alive(x, y-1, 'n') || alive(x, y+1, 's') || alive(x-1, y, 'w');
            else return alive(x, y-1, 'n') || alive(x, y+1, 's') || alive(x+1, y, 'e');
        }
    }
}

void dump(char map[][1000], int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf(" %hd %hd", &y_max, &x_max);

    short e_x, e_y;
    for (int i=0; i<y_max; i++) {
        for( int j=0; j<x_max; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'e') {
                e_y = i;
                e_x = j;
            }
        }
    }
    //dump(map, m, n);

    if (alive(e_x, e_y, '0')) {
        printf("Alive!\n");
    }
    else {
        printf("Dead!\n");
    }
}
