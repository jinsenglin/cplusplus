/*
An equation in prefix notation.

Operands are integers in the range between 0 and 9.

There are four operators in this problem: addition('+'), subtraction('-'), 
multiplication('*'), and division('/').

At the end of an equation there is a '=' symbol. 

No blank space between elements.

No calculate errors(for example, 5/0) will happen.

The length of equations (includes '=') is less than 40.

Show the answer of equation

Note that the answer may be a decimal number, so you are asked to use '%.3f' to show the answer, 
or you'll get WA even if your answer is correct.

No new line character at the end. 


/4*2+13=
(4/(2*(1+3)))
0.500

*+23+4+-56-78
((2+3)*(4+((5-6)+(7-8))))=10

*/

#include <stdio.h>
#include <ctype.h>

double calculate(void);

int main(void)
{
    printf("%.3f", calculate());
    return 0;
}

double calculate(void) {
    int c;
    double ans;
    double op1, op2;

    c = getchar();
    if (c=='+') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 + op2;
    } else if (c=='-') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 - op2;
    } else if (c=='*') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 * op2;
    } else if (c=='/') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 / op2;
    } else if (isdigit(c)) {
        ans = c-48;
    }

    return ans;
}
