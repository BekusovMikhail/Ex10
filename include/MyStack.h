// Copyright 2021 Bekusov Mikhail

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class Tmp>
class MyStack {
 private:
    Tmp *stack;
    int sz;
    int hd;

 public:
    explicit MyStack(int count) {
        sz = count;
        hd = 0;
        stack = new Tmp[count];
    }

    MyStack(const MyStack &stck) {
        sz = stck.sz;
        hd = stck.hd;
        stack = new Tmp[sz];
        for (int i = 0; i < hd; ++i) {
            stack[i] = stck.stack[i];
        }
    }

    bool isFull() const {
        return hd == sz;
    }

    bool isEmpty() const {
        return hd == 0;
    }

    Tmp pop() {
        if (isEmpty()) {
            throw "Empty stack";
        } else {
            hd--;
            return stack[hd];
        }
    }

    void push(Tmp el) {
        if (isFull()) {
            throw "Full stack";
        } else {
            stack[hd] = el;
            hd++;
        }
    }

    Tmp get() const {
        return stack[hd - 1];
    }

    ~MyStack() {
        delete[] stack;
    }
};

#endif  // INCLUDE_MYSTACK_H_