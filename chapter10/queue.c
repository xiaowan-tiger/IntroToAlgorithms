#include <stdio.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE 8
int queue[QUEUE_MAX_SIZE];
int head = -1;
int tail = -1;

bool isEmpty() {
    if ((head == -1) && (tail == -1))
        return true;
    else
        return false;
}

bool isFull() {
    if ((head != -1) && (head == tail)) 
        return true;
    else
        return false;
}

void enqueue(int x) {
    if (isEmpty()) {
        head += 1;
        tail += 2;
        queue[head] = x;
    } else if (!isFull()) {
        queue[tail] = x;
        tail = (tail + 1) % QUEUE_MAX_SIZE;
    } else {
        printf("queue is full, nothing can be added\n");
    }
}

int dequeue() {
    int ret = -1;
    if (!isEmpty()) {
        ret = queue[head];
        if (head == tail){ 
            head = -1;
            tail = head;
        } else 
            head = (head + 1) % QUEUE_MAX_SIZE;
    } else {
        printf("queue is empty, nothing can be poped\n"); 
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    enqueue(9);
    enqueue(8);
    enqueue(7);
    enqueue(6);
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);

    while(!isEmpty()) {
        printf("poped data is: %d\n", dequeue());
    }


    return 0;
}


