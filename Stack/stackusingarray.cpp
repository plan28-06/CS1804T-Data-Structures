#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class stack{
    char arr[5];
    int top;
    public:
        stack(){
            top = -1;
        }
        void push(char c); // Time complexity is O(1)
        void peek(); // Time complexity is O(1)
        void pop(); // Time complexity is O(1)
};




int main(){
    stack stack1;
    int choice;
    char character;
    while(true){ 
        system("clear");
        printf("Enter \n1. Push\n2. Pop\n3. Peek");
        printf("\n4. Exit\n");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        if (choice ==1){
            printf("Enter character to insert:");
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

void stack::push(char c){
    if (top == 4){
        printf("stack is full\n");
    }
    else{
        arr[top+1] = c;
        top++;
        printf("Element pushed");
    }
}

void stack::pop(){
    if (top == -1){
        printf("The stack is empty");
    }
    else{
        printf("Element %c popped",arr[top]);
        top = top -1;
        printf("Element popped");
    }
}

void stack::peek(){
    if (top == -1){
        printf("The stack is empty");
    }
    else{
        printf("The element at the top is %c\n", arr[top]);
    }
}