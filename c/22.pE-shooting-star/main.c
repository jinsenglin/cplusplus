#include <stdio.h>
#include <stdbool.h>

/*
Input
The first line has three numbers, C, F and H, which respectively means the length of the ceiling, the length of the floor, and the height between the ceilings and floors.

The second line has a number S, which means the start point of shooting object. It's noted that the location below the ceiling is 1, and the location below that is 2, and so on.

1 ≤ C, F ≤ 20
2 ≤ H ≤ 20
1 ≤ S ≤ H
The third line has a character 'u' or 'd'. It  corresponds to the initial direction of shooting.

u: upper-right in 45 degree
d: lower-right in 45 degree
There are only one case for each testcase

Output
Draw the map and the route of the shooting object.
The route of shooting object is marked as '*', which appears until the object is out of boundaries.

You need to use a (H+2)*(max{C, F, the horizontal length of route of shooting}) array to print out the result

(for example, 範例一 print 5*10 array)

Remember there is '\n' in the end.

Sample Input 1
5 7 3
1
d

Sample Output 1
-----    *
*   *   * 
 * * * *  
  *   *   
------- 

Sample Input 2
8 7 4
4
u

Sample Output 2
--------  *
   *     * 
  * *   *  
 *   * *   
*     *    
-------
*/

char map[22][40] = {' '};
int C, F, H;
int S;
int L = 40;
char D;

void display() {
    for (int i=0; i<H+2; i++) {
        for (int j=0; j<L; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

bool out_of_bound(int y, int x) {
    return (y == 0 && x>C) || (y == (H+1) && c>F)
}

bool the_ceil(int y, int x) {
    return (y == 0 && x<C);
}

bool the_floor(int y, int x) {
    return (y == (H+1) && x<F);
} 

void paint_shoot(int origin_y, int origin_x, char d) {
    int y = origin_y;
    int x = origin_x;
    char next_d;

    map[y][x] = '*';
    if ( d == 'u' ) {
        while (true) {
            y--;
            x++;
            if (!the_ceil(y, x) && !out_of_bound(y, x)) map[y][x] = '*';
            else {
                y++;
                x--;
                break;
            }
        }
        next_d = 'd';
    }
    else { // i.e., (d == 'd')
        while (true) {
            y++;
            x++;
            if (!the_floor(y, x) && !out_of_bound(y, x)) map[y][x] = '*';
            else {
                y--;
                x--;
                break;
            }
        }
        next_d = 'u';
    }

    if (!out_of_bound(y, x)) paint_shoot(y, x, next_d);
}

void paint_map() {
   for (int i=0; i<C; i++) map[0][i] = '-';
   for (int i=0; i<F; i++) map[H+1][i] = '-';
   map[S][0] = '*';
}

void load() {
    scanf(" %d %d %d", &C, &F, &H);
    scanf(" %d", &S);
    scanf(" %c", &D);
}

int main() {

    /*
    ceil  starts from (0, 0)    ends to (0, C-1);
    shoot starts from (S, 0)    ends to (?, L-1);
    floor starts from (H+1, 0)  ends to (H+1, F-1);
    */

    load();
    paint_map();
    paint_shoot(S, 0, D);
    display();
}
