#include <stdio.h>
#include <stdbool.h>

// #define int bool
#define STACK_MAX_SIZE 8
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

int main(int argc, char const *argv[])
{

    push(5);
    push(6);
    push(8);
    push(3);
    push(13);
    push(65);
    push(50);
    push(50);
    push(50);
    push(50);
    push(50);
    push(50);


    while(!isEmpty()) {
        printf("poped data is %d \n", pop());
    }
    pop()

    /* code */
    return 0;
}


