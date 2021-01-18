// Copyright 2021 Bekusov Mikhail

#include "postfix.h"

int p(char c) {
    switch (c) {
        case '*':
            return 3;
        case '/':
            return 3;
        case '+':
            return 2;
        case '-':
            return 2;
        case '(':
            return 0;
        case ')':
            return 1;
        default:
            return -99;
    }
}

std::string infix2postfix(std::string infix) {
    MyStack<char> stk(400);
    std::string out;
    for (int i = 0; i < infix.length(); ++i) {
        if (infix[i] == 32) {
            continue;
        } else if (p(infix[i]) == 2 || p(infix[i]) == 3) {
            if (stk.isEmpty()) {
                stk.push(infix[i]);
            } else {
                while (p(stk.get()) >= p(infix[i])) {
                    out.push_back(stk.pop());
                    out.push_back(' ');
                }
                stk.push(infix[i]);
            }
        } else if (infix[i] == 40) {
            stk.push(infix[i]);
        } else if (infix[i] == 41) {
            while (p(stk.get()) != 0) {
                out.push_back(stk.pop());
                out.push_back(' ');
            }
            stk.pop();
        } else if (infix[i] == 46) {
            out.pop_back();
            out.push_back(infix[i]);
        } else {
            out.push_back(infix[i]);
            if (!(infix[i + 1] <= '9' && infix[i + 1] >= '0')) {
                out.push_back(' ');
            }
        }
    }
    while (!stk.isEmpty()) {
        out.push_back(stk.pop());
        out.push_back(' ');
    }
    out.pop_back();
    return out;
}