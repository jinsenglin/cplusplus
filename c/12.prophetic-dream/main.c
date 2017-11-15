#include <stdio.h>
#include <stdlib.h>

#define for RF
#define while RF
#define goto RF

#include "code.c"

int input[20];

void read_input(int num)
{
	if(num>1) read_input(num-1);
	scanf("%d", &input[num-1]);
}

int main()
{
	int ans, N;
	scanf("%d", &N);
	read_input(N);
    ans = maxElement(input, N);
    printf("%d\n",ans);
    return 0;
}
