#include <stdio.h>
#include <stdlib.h>

#define for RF
#define while RF
#define goto RF

#include "code.c"

int main(){
	int month, ans;
	scanf("%d", &month);
	printf("%d\n", Rabbit(month));
	return 0;
}
