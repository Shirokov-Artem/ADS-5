// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T data[size];
    int topIndex;

public:
    TStack() : topIndex(-1) {}

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == size - 1;
    }

    void push(const T& value) {
        if (!isFull()) {
            topIndex++;
            data[topIndex] = value;
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        }
    }

    T top() const {
        if (!isEmpty()) {
            return data[topIndex];
        }
        return T();
    }
};
#endif  // INCLUDE_TSTACK_H_
