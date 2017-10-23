#include "function.h"

class Stack {
private:
    int top;
    char stack[1024];
public:
    Stack() {
        // init top
        top = -1;
    }

    void push(char c) {
        // update stack and top
        top += 1;
        stack[top] = c;
    }

    char pop() {
        char poped_value;

        if (top > -1) {
            poped_value = stack[top];

            // update top
            top -= 1;
        }
        else {
            poped_value = '\0'; // TODO: refactor
        }

        return poped_value;
    }

    std::string to_string() {
        return std::string(stack);
    }
};

class IntStack {
private:
    int top;
    int stack[1024];
public:
    IntStack() {
        // init top
        top = -1;
    }

    void push(int i) {
        // update stack and top
        top += 1;
        stack[top] = i;
    }

    int pop() {
        char poped_value;

        if (top > -1) {
            poped_value = stack[top];

            // update top
            top -= 1;
        }
        else {
            poped_value = 0; // TODO: refactor
        }

        return poped_value;
    }
};


class Implement : public Parenthesis {
private:
    bool has_operand;
    std::string revised_expression;
    std::string postfix_expression;

    void eval_postfix() {
        int value = 0;

        IntStack *stack = new IntStack();

        char c;
        int left_operand;
        int right_operand;

        // scan each character of postfix_expression, from left to right, one chracter one time till \0
        for (int i=0; ; i++) {
            c = postfix_expression[i];

            if (c == '\0') {
                // break for loop when the end of line \0 is scanned
                break;
            }
            else {
                // update stack
                switch (c) {
                    case '+':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand + right_operand);
                        break;
                    case '-':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand - right_operand);
                        break;
                    case '*':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand * right_operand);
                        break;
                    case '/':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand / right_operand);
                        break;
                    default:
                        stack->push(c - '0');
                        break; 
                }
            }
        }
        
        // update value
        value = stack->pop();

        // print the evaluated value
        std::cout<<value<<std::endl;
    }

    void infix_to_postfix() {
        std::cout<<"DEBUG: infix_to_postfix() NOT YET IMPLEMENTED"<<std::endl;
        Stack *stack = new Stack();

        char c;

        // scan each character of revised_expression, from left to right, one chracter one time till \0
        for (int i=0; ; i++) {
            c = revised_expression[i];

            if (c == '\0') {
                // break for loop when the end of line \0 is scanned
                break;
            }
            else {
                // TODO set postfix_expression
                switch (c) {
                    case '+':
                        break;
                    case '-':
                        break;
                    case '*':
                        break;
                    case '/':
                        break;
                    case '{':
                        break;
                    case '}':
                        break;
                    case '[':
                        break;
                    case ']':
                        break;
                    case '(':
                        break;
                    case ')':
                        break;
                    default:
                        break; 
                }
            }
        }
    }

    void validate_and_revise_if_needed(std::string s) {
        bool is_valid = true;

        Stack *stack1 = new Stack();
        Stack *stack2 = new Stack();

        char c1;
        char c2;

        // scan each character of the input line, from left to right, one chracter one time till \0
        // set is_valid false if any correction made
        // set has_operand true if any operand found
        for (int i=0; ; i++) {
            c1 = s[i];

            if (c1 == '\0') {
                // break for loop when the end of line \0 is scanned
                break;
            }
            else {
                // check expression validity before push character into stack
                switch (c1) {
                    case '{':
                        // no check, just push
                        stack1->push(c1);
                        stack2->push(c1);
                        break;
                    case '}':
                        // check
                        // if c2 == '{' then make no correction
                        // if c2 == '\0' then make a correction by ignoring c1
                        // if c2 == something else then make a correction by replacing c1
                        c2 = stack1->pop();
                        switch (c2) {
                            case '{':
                                stack2->push(c1);
                                break;
                            case '\0':
                                is_valid = false;
                                break;
                            case '[':
                                is_valid = false;
                                stack2->push(']');
                                break;
                            case '(':
                                is_valid = false;
                                stack2->push(')');
                                break;
                        }
                        break;
                    case '[':
                        // no check, just push
                        stack1->push(c1);
                        stack2->push(c1);
                        break;
                    case ']':
                        // check
                        // if c2 == '[' then make no correction
                        // if c2 == '\0' then make a correction by ignoring c
                        // if c2 == something else then make a correction by replacing c
                        c2 = stack1->pop();
                        switch (c2) {
                            case '[':
                                stack2->push(c1);
                                break;
                            case '\0':
                                is_valid = false;
                                break;
                            case '{':
                                is_valid = false;
                                stack2->push('}');
                                break;
                            case '(':
                                is_valid = false;
                                stack2->push(')');
                                break;
                        }
                        break;
                    case '(':
                        // no check, just push
                        stack1->push(c1);
                        stack2->push(c1);
                        break;
                    case ')':
                        // check
                        // if c2 == '(' then make no correction
                        // if c2 == '\0' then make a correction by ignoring c
                        // if c2 == something else then make a correction by replacing c
                        c2 = stack1->pop();
                        switch (c2) {
                            case '(':
                                stack2->push(c1);
                                break;
                            case '\0':
                                is_valid = false;
                                break;
                            case '{':
                                is_valid = false;
                                stack2->push('}');
                                break;
                            case '[':
                                is_valid = false;
                                stack2->push(']');
                                break;
                        }
                        break;
                    default:
                        // no check, just push
                        has_operand = true;
                        stack2->push(c1);
                        break;
                }
            }
        }

        // complement ')' ']' '}' if stack1 is not empty
        while ((c2 = stack1->pop()) != '\0') {
            is_valid = false;
            switch (c2) {
                case '{':
                    stack2->push('}');
                    break;
                case '[':
                    stack2->push(']');
                    break;
                case '(':
                    stack2->push(')');
                    break;
            }
        }

        // set revised_expression
        revised_expression = stack2->to_string();

        // print True of False
        if (is_valid) {
            std::cout<<"True"<<std::endl;
        }
        else {
            std::cout<<"False"<<std::endl;

            // print the revised expression
            std::cout<<revised_expression<<std::endl;
        }
    }

public:
    void isValid(std::string s) {
        has_operand = false;

        validate_and_revise_if_needed(s);
        if (has_operand) {
            infix_to_postfix();
            eval_postfix();
        }
        else {
            std::cout<<"0"<<std::endl;
        }
    }
};
