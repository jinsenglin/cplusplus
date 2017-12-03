#include <stdio.h>

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

int main() {
}
