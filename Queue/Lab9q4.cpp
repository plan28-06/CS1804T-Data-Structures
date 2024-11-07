#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class circularqueueusingll{
    public:
        struct node{
            int data;
            struct node * next;
            struct node * prev;
        };
        struct node * head;
        struct node * front;
        struct node * rear;
        circularqueueusingll(){
            front = rear = head =NULL;
        }
        void enqueue(int); // Time Complexity is O(1) 
        int dequeue(); // Time Complexity is O(1)
        void peek(); // Time Complexity is O(1)
};


int main(){
    circularqueueusingll q;
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


void circularqueueusingll::enqueue(int num){
    if (front == NULL && rear == NULL){
        struct node * newnode = (struct node *)(malloc(sizeof(node)));
        newnode->data = num;
        newnode->prev = rear;
        head = newnode;
        newnode->next = head;
        front = head;
        rear = head;
        printf("Number Inserted :)");
    }
    else{
        struct node * newnode = (struct node *)(malloc(sizeof(node)));
        newnode->data = num;
        newnode->next = head;
        newnode->prev = rear;
        rear->next = newnode;
        rear = rear->next;
        printf("Number Inserted :)");
    }
}

int circularqueueusingll::dequeue(){
    if (front == NULL && rear == NULL){
        printf("The Queue is empty\n");
        return -1;
    }
    else if (front  == head && rear == head){
        int temp = front ->data;
        front  = rear = head =NULL;
        printf("Number Deleted :)");
        return temp;
    }
    else{
        int temp = front->data;
        front = front->next;
        head = front;
        printf("Number Deleted :)");
        return temp;
    }
}

void circularqueueusingll::peek(){
    if (rear == NULL && front == NULL){
        printf("The Queue is empty\n");
    }
    else{
        printf("\n%d\n",rear->data);
    }
}