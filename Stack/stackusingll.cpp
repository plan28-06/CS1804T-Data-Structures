#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class stackll{
    int count = 0;
    struct node {
        int data;
        struct node * next;
    };
    struct node * head;
    struct node * tail;
    public:
        stackll(){
            head = NULL;
            tail = NULL;
        };
        void push(char c); // Time complexity is O(1)
        void peek(); // Time complexity is O(1)
        void pop(); // Time complexity is O(n)
};




int main(){
    stackll stack1;
    int choice;
    char character;
    while(true){ 
        system("clear");
        printf("Enter \n1. Push\n2. Pop\n3. Peek");
        printf("\n4. Exit\n");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        if (choice ==1){
            printf("Enter number to insert:");
            cin >> character;
            stack1.push(character);
        }
        else if (choice == 2){
            stack1.pop();
        }
        else if (choice == 3){
            stack1.peek();
        }
        else if (choice == 4 ){
             exit(1);
        }
        getchar();
        getchar();
        
    }
    return 0;
}

void stackll::push(char c){
    if (head == NULL){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = c;
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
        count++;
        printf("Element pushed");
    }
    else{
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = c;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        count++;
        printf("Element pushed");
    }
}

void stackll::pop(){
    if (head == NULL){
        printf("The stack is empty");
    }
    else{
        if (head==tail){
            printf("Element %c popped",tail->data);
            head = NULL;
            tail = NULL;
            count--;
        }
        else if (count == 2){
            printf("Element %c popped",tail->data);
            head->next = NULL;
            tail = head;
            count--;
        }
        else{
            printf("Element %c popped",tail->data);
            struct node * tempnode = head;
            for (int i = 0 ; i<count-2; i++){
                tempnode = tempnode->next;
            }
            tempnode->next = NULL;
            tail = tempnode;
            count--;
        }
    }
}

void stackll::peek(){
    if (tail == NULL){
        printf("Stack is empty");
    }
    else{
        printf("The element at the top is %c ",tail->data);
    }
}