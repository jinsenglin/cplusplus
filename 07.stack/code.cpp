#include "function.h"

class Stack {
private:
    int top;
    char stack[1024];
public:
    void push(char c) {
        //TODO: update stack and top
    }

    char pop() {
        char poped_value = '\0';
        //TODO: set poped_value

        //TODO: update stack and set top

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
        // TODO: set value

        // print the evaluated value
        std::cout<<value<<std::endl;
    }

    void infix_to_postfix() {
        // TODO: set postfix_expression
    }

    void revise(std::string s) {
        Stack *stack = new Stack();
        // scan character in ths string s, one chracter one time till \0
        for (int i=0; ; i++) {
            if (s[i] == '\0') {
                break;
            }
            else {
                // TODO:
            }
        }

        bool is_valid = true;
        // TODO: set is_valid false if any correction made

        // TODO: set revised_expression

        // TODO: set has_operand true if any operand found
        // has_operand = true;

        // print True of False
        if (is_valid) {
            std::cout<<"True"<<std::endl;
        }
        else {
            std::cout<<"False"<<std::endl;
        }

        // print the revised expression if !is_valid
        if (!is_valid) {
            std::cout<<revised_expression<<std::endl;
        }
    }

public:
    void isValid(std::string s) {
        has_operand = false;

        revise(s);
        if (has_operand) {
            infix_to_postfix();
            eval_postfix();
        }
        else {
            std::cout<<"0"<<std::endl;
        }
    }
};
