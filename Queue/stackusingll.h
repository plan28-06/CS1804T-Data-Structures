#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class stackll{
    int count = 0;
    struct node {
        string data;
        struct node * next;
    };
    struct node * head;
    struct node * tail;
    public:
        stackll(){
            head = NULL;
            tail = NULL;
        };
        void push(string c); // Time complexity is O(1)
        string peek(); // Time complexity is O(1)
        string pop(); // Time complexity is O(n)
        int isempty(); // Time complexity is O(1)
};


void stackll::push(string c){
    if (head == NULL){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = c;
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
        count++;
    }
    else{
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = c;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        count++;
    }
}

string stackll::pop(){
    string c;
    if (head == NULL){
        return "Empty";
    }
    else{
        if (head==tail){
            c= head->data;
            head = NULL;
            tail = NULL;
            count--;
        }
        else if (count == 2){
            c=head->next->data;
            head->next = NULL;
            tail = head;
            count--;
        }
        else{
            struct node * tempnode = head;
            for (int i = 0 ; i<count-2; i++){
                tempnode = tempnode->next;
            }
            c = tempnode->next->data;
            tempnode->next = NULL;
            tail = tempnode;
            count--;
        }
        return c;
    }
}

string stackll::peek(){
    if (tail == NULL){
        return "Empty";
    }
    return tail->data;
}

int stackll::isempty(){
    if (head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}