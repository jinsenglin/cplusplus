#include<stdio.h>
#include<string.h>

/*
Input
There are multiple lines in each testcase. Each line contains a string si that HT writes on the paper.

The input file is ended by 'EOF'.

It is guaranteed that :

At most 10 lines in each testcase.
testcase #1 : Sample Input
testcase #2~4 : 1 ≤ | si | ≤ 10, at most one "lucky number" appears in each line
testcase #5~8 : 1 ≤ | si | ≤ 100
testcase #9 : 1 ≤ | si | ≤ 5000
testcase #10 : 1 ≤ | si | ≤ 200000
If you can't pass testcase #9 & #10 immediately, try to solve another two problems first. 

Output
For each string si, please output a line contains one integer representing the number of "lucky substrings" in si.
*/

void run_testcase(char *str) {
    printf("DEBUG: str = %s\n", str);

    unsigned long len = strlen(str);
    printf("DEBUG: len(str) = %lu\n", len);

    for (int i=0; i<len; i++) {
        char c = str[i];
        printf("DEBUG: c = %c\n", c);

        if (c == '9') {
            // TODO
        }
    }
}

void load_testdata(char *str) {
    while (scanf("%s", str) != EOF) {
        //printf("DEBUG: str = %s\n", str);
        run_testcase(str);
    }
}

int main(){
    char str[200001];
    load_testdata(str);
    return 0;  
}
