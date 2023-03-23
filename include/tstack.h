// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <stdexcept>
#include <iostream>

template<typename T, int size>
class TStack {
 private:
  T* data;
  int count;

 public:
  TStack() {
    data = new T[size];
    count = 0;
  }
  ~TStack() {
    delete[] data;
  }
  void push(T value) {
    if (count == size) { // проверка на переполнение стека
      throw std::out_of_range("Stack overflow");
    }
    data[count++] = value;
  }
  T pop() {
    if (count == 0) { // проверка на пустой стек
      throw std::out_of_range("Stack is empty");
    }
    return data[--count];
  }
  T top() const {
    if (count == 0) { // проверка на пустой стек
      throw std::out_of_range("Stack is empty");
    }
    return data[count - 1];
  }
  bool isEmpty() const { // проверка на пустоту стека
    return count == 0;
  }
};
#endif  // INCLUDE_TSTACK_H_
