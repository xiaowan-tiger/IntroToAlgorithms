#include <stdio.h>
#include "stack.h"
// #define int bool
#define STACK_MAX_SIZE 64
// typedef true 1;
// typedef false 0;
int stack[STACK_MAX_SIZE];
int top = -1;

bool isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}

int get_stack_size() {
    return top + 1;
}

bool isFull() {
    if (top == STACK_MAX_SIZE)
        return true;
    else
        return false;
}

void push(int x) {
    if (!isFull()) {
        top += 1;
        stack[top] = x;
    } else {
        printf("stack is full, nothing can be pushed\n");
    }
}

int pop() {
    int ret = -1;
    if (!isEmpty()) {
        ret = stack[top];
        top -= 1;
    } else {
        printf("stack is empty, nothing can be poped\n");
    }
    return ret;
}
