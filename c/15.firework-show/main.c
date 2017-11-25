#include<stdio.h>
#include<string.h>

/*
Input

The first line contains an integer T, representing the number of testcases.

Each testcase contains two lines :

The first line contains two integer n, m, representing the number of fireworks and the supreme leader's request.

The second line contains n integer ai, representing the beauty grade of each firework.

It is guaranteed that :

1 ≤ T ≤ 10
1 ≤ n ≤ 20
1 ≤ m ≤ 50000
1 ≤ ai ≤ 2000

Output

For each testcase, please output a line contains one integer represents the number of different kinds of shows that meet the supreme leader’s demanding request.


Sample Input

3
3 5
1 2 3
6 3
1 1 1 1 1 1
6 6
1 2 3 1 2 3

Sample Output

1
1
3
*/

void run_testcase(int *m, int *data) {
    //printf("DEBUG: m = %d\n", *m);

    int result = -1;

    printf("%d\n", result);
}

void load_testdata(int *T, int *n, int *m, int data[]) {
    scanf("%d", T);
    //printf("DEBUG: T = %d\n", *T);

    for (int t=0; t<*T; t++) {
        //printf("DEBUG: case %d\n", t+1);

        scanf("%d", n);
        //printf("DEBUG: n = %d\n", *n);

        scanf("%d", m);
        //printf("DEBUG: m = %d\n", *m);

        for (int i=0; i<*n; i++) {
            scanf("%d", &data[i]);
            printf("DEBUG: i = %d, a[i] = %d\n", i, data[i]);
        }

        run_testcase(m, data);
    }
}

int main(){
    int T_MIN = 1;
    int T_MAX = 10;
    int n_MIN = 1;
    int n_MAX = 20;
    int m_MIN = 1;
    int m_MAX = 50000;
    int ai_MIN = 1;
    int ai_MAX = 2000;

    int T;
    int n;
    int m;
    int data[n_MAX]; 

    load_testdata(&T, &n, &m, data);
    return 0;  
}
