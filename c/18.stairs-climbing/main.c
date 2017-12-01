#include <stdio.h>

/*
Input
An integer N represents the number of testcases.

Then , there are following N lines.

Each line contain an integer X that  represents the number of stairs in that testcase.

P.S. 1<= X <=40

Output
An integer represents the number of possible way to climb N stairs.

Note that you have to add '\n' at the end of output

Sample Input
3
3
5
7

Sample Output
3
8
21
*/

void fn(int X) {
    printf("DEBUG: X = %d\n", X);
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        int X;
        scanf(" %d", &X);
        fn(X);
    }
}
