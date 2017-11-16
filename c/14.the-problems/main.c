#include<stdio.h>
#include<string.h>

/*
Input
The first line contains an integer n, representing the number of problems TA give to HT.

The second line contains n integers ai, representing the quality score of each question.

It is guaranteed that :

testcase #1 : Sample Input
testcase #2~3 : 1 ≤ n ≤ 100, 1 ≤ ai ≤ 3
testcase #4~6 : 1 ≤ n ≤ 100, 1 ≤ ai ≤ 100
testcase #7~9 : 1 ≤ n ≤ 100, -100 ≤ ai ≤ 100
testcase #10 : 1 ≤ n ≤ 2*105, -105 ≤ ai ≤ 105

Output
Please output a line represents the number of different kinds of "quality score" in the problem set.

Sample Input
5
-1 -1 -1 2 2

Sample Output
2
*/

void run_testcase(int *n, int *problems) {
    //printf("DEBUG: n = %d\n", *n);

    int result = -1;

    printf("%d\n", result);
}

void load_testdata(int *n, int *problems) {
    scanf("%d", n);
    //printf("DEBUG: n = %d\n", *n);

    for (int p=0; p<*n; p++) {
        scanf("%d", &problems[p]);
        //printf("DEBUG: problem quality score = %d\n", problems[p]);
    }

    run_testcase(n, problems);
}

int main(){
    int n;
    int problems[200001];
    load_testdata(&n, problems);
    return 0;  
}
