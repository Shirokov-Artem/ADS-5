// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <stack>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack;
  std::string result;
  std::map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
  for (char c : inf) { // перебираю символы входной строки
    if (isdigit(c)) {
      result += c;
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        result += ' ';
        result += stack.pop();
      }
      stack.pop();
    } else {
      while (!stack.isEmpty() && stack.top() != 
             '(' && priority[c] <= priority[stack.top()]) {
        result += ' ';
        result += stack.pop();
      }
      result += ' ';
      stack.push(c);
    }
  }

  while (!stack.isEmpty()) {
    result += ' ';
    result += stack.pop();
  }

  return result;
}

int eval(std::string pref) {
  TStack<int, 100> stack;
  for (char c : pref) { // перебираю символы входной строки
    if (isdigit(c)) {
      stack.push(c - '0');
    } else if (c == ' ') {
      continue;
    } else {
      int op2 = stack.pop();
      int op1 = stack.pop();
      switch (c) {
        case '+':
          stack.push(op1 + op2);
          break;
        case '-':
          stack.push(op1 - op2);
          break;
        case '*':
          stack.push(op1 * op2);
          break;
        case '/':
          stack.push(op1 / op2);
          break;
      }
    }
  }

  return stack.top();
}
