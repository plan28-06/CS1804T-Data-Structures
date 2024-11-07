#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;


class queue{
    public:
        int que[5];
        int front;
        int rear;
        queue(){
            front = rear = -1;
        }
        void enqueue(int); // Time Complexity is O(1)
        int dequeue(); // Time Complexity is O(1)
        void peek(); // Time Complexity is O(1)
};

int main(){
    queue q;
    while (1){
        system("cls");
        int ch,n;
        printf("1. Enqueue\t2. Deque\t3. Peek\t4. Exit:\n");
        cin >> ch;
        if (ch==1){
            printf("Enter number to insert:");
            cin >> n;
            q.enqueue(n);
        }
        else if (ch==2){
            q.dequeue();
        }
        else if (ch==3){
            q.peek();
        }
        else if (ch==4){
            exit(1);
        }
        else{
            printf("\nEnter a valid choice\n");
        }
        getchar();
        getchar();
    }
}

void queue::enqueue(int num){
    if (rear == 4){
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1){
        que[rear + 1] = num;
        front++;
        rear++;
        printf("Number Inserted :)");
    }
    else{
        que[rear + 1] = num;
        rear++;
        printf("Number Inserted :)");
    }
}

int queue::dequeue(){
    if (front == -1){
        printf("The Queue is empty\n");
        return -1;
    }
    else if (front  == rear){
        int temp = rear;
        front  = rear = - 1;
        printf("Number Deleted :)");
        return que[temp];
    }
    else{
        front++;
        printf("Number Deleted :)");
        return que[front - 1];
    }
}

void queue::peek(){
    if (rear == -1){
        printf("The Queue is empty\n");
    }
    else{
        printf("\n%d\n",que[rear]);
    }
}