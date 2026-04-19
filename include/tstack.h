// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int kSize>
class TStack {
 private:
  T data[kSize];
  int topIndex;

 public:
  TStack() {
    topIndex = -1;
  }

  bool empty() {
    return topIndex == -1;
  }

  void push(T value) {
    topIndex++;
    data[topIndex] = value;
  }

  void pop() {
    topIndex--;
  }

  T top() {
    return data[topIndex];
  }
};

#endif  // INCLUDE_TSTACK_H_
