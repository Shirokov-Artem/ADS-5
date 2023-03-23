// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <stack>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack;
  std::string result;
  std::map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // таблица приоритетов
  for (char c : inf) { // перебираю символы входной строки
    if (isdigit(c)) { // если символ - цифра, добавляю его в выходную строку
      result += c;
    } else if (c == '(') { // символ - открывающая скобка, помещаю ее в стек
      stack.push(c);
    } else if (c == ')') { // символ - закрывающая скобка
      while (!stack.isEmpty() && stack.top() != '(') { // извлекаю из стека и добавляю в выходную строку, пока не появится открывающая скобка
        result += ' ';
        result += stack.pop();
      }
      stack.pop();
    } else {
      while (!stack.isEmpty() && stack.top() != '(' && priority[c] <= priority[stack.top()]) { // извлекаю из стека и добавляю в выходную строку, пока не появится меньший приоритет или открывающая скобка
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
    if (isdigit(c)) { // если символ - цифра, преобразую его в число и помещаем в стек
      stack.push(c - '0');
    } else if (c == ' ') { // если символ - пробел, пропускаю его
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
