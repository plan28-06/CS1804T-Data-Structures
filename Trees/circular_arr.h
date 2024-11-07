#include <stdio.h>
#include <stdlib.h>
// Define the tree node structure globally
struct node {
    char data;
    struct node* left;
    struct node* right;
};

class Queue {
public:
    struct node* arr[100];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(struct node* num);
    struct node* dequeue();
    int isempty();
};

// Enqueue function
void Queue::enqueue(struct node* num) {
    if ((rear + 1) % 100 == front) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) { // First element to insert
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % 100;
    }
    arr[rear] = num;
}

// Dequeue function
struct node* Queue::dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return nullptr;
    }

    struct node* temp = arr[front];
    if (front == rear) {
        // Queue becomes empty after this dequeue
        front = rear = -1;
    } else {
        front = (front + 1) % 100;
    }
    return temp;
}

// IsEmpty function
int Queue::isempty() {
    if (front == -1 && rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}