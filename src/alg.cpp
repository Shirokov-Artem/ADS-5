// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <stack>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    std::map<char, int> priority = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}};
    std::string result = "";
    std::stack<char> stack;
    for (int i = 0; i < inf.size(); i++) {
        char c = inf[i];
        if (isdigit(c)) {
            result += c;
            // если следующий символ - не цифра, то добавляем пробел
            if (i + 1 < inf.size() && !isdigit(inf[i + 1])) {
                result += ' ';
            }
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (stack.top() != '(') {
                result += ' ';
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.empty() && priority[c] <= priority[stack.top()]) {
                result += ' ';
                result += stack.top();
                stack.pop();
            }
            result += ' ';
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        result += ' ';
        result += stack.top();
        stack.pop();
    }
    return result;
}

int eval(std::string pref) {
    std::stack<int> stack;
    for (int i = 0; i < pref.size(); i++) {
        char c = pref[i];
        if (isdigit(c)) {
            int num = c - '0';
            while (i + 1 < pref.size() && isdigit(pref[i + 1])) {
                num = num * 10 + (pref[i + 1] - '0');
                i++;
            }
            stack.push(num);
        } else if (c == ' ') {
            continue;
        } else {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            switch (c) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
            }
        }
    }
    return stack.top();
}
