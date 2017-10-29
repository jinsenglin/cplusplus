#include<stdio.h>
#include<string.h>

/*
Input
First 5 lines describe the card. Each line contains 5 integers between 1 and 25.

( We guarantee that all 25 numbers are distinct. )

Next line contains an integer T ( 1 <= T <= 100 ), number of testcases.

Following are T testcases, and each of them contains 2 lines.

The first line of each testcase contains an integer N ( 1 <= N <= 25 ), number of selected numbers.

The second line contains N distinct selected numbers, from 1-st to N-th.

Output
For each testcase, print out an integer x, telling eccioa he can get the reward at x-th number, with x as small as possible. If he couldn't, tell him that he did not get the reward yet.

See Sample Output for more information about output format.
*/

int is_bingo(int board[5][5]) {
    // TODO
    return 0;
}

void run_testcase(int board[5][5], int Tth, int N, int Nth[]) {
    int _board[5][5] = {0};
    char *result = "Not yet \\(^o^)/";

    // TODO: update _board

    if ( is_bingo(_board) ) {
        // TODO: update result
        result = "?";
    }

    printf("Case #%d: %s\n", Tth, result); 
}

void load_testdata(int board[5][5]) {
    for (int i=0; i<5; i++) {
        scanf("%d %d %d %d %d", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4]);
        //printf("DEBUG: %d %d %d %d %d\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
    }
   
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        int N;
        scanf("%d", &N);

        int Nth[N];
        for (int j=0; j<N; j++) {
            int n;
            scanf("%d", &n);
            //printf("DEBUG: n = %d\n", n);

            Nth[j] = n;
            //printf("DEBUG: j = %d, Nth[j] = %d\n", j, Nth[j]);
        }

        run_testcase(board, i+1, N, Nth);
    }
}

int main(){
    int board[5][5];
    load_testdata(board);

    return 0;  
}
