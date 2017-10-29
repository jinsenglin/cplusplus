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

void run_testcase(int board[5][5], int Tth, int N, int numbers[]) {
    int _board[5][5] = {0};

    for (int i=0; i<N; i++) {
        int Nth = i+1;

        // TODO: update _board

        if ( is_bingo(_board) ) {
            printf("Case #%d: %d\n", Tth, Nth);
            return;
        }
    }

    printf("Case #%d: Not yet \\(^o^)/\n", Tth); 
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

        int numbers[N];
        for (int j=0; j<N; j++) {
            int n;
            scanf("%d", &n);
            //printf("DEBUG: n = %d\n", n);

            numbers[j] = n;
            //printf("DEBUG: j = %d, numbers[j] = %d\n", j, numbers[j]);
        }

        run_testcase(board, i+1, N, numbers);
    }
}

int main(){
    int board[5][5];
    load_testdata(board);

    return 0;  
}
