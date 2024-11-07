#include<stdio.h>
#include<iostream>
#include<stdlib.h>


class doublylinkedlist{
    public:
        int count=0;
        struct node {
            struct node * prev;
            int data;
            struct node * next;
        };
        struct node * head; 
        doublylinkedlist(){
            head = NULL;
        }
        int current=-1;
        void insertbeg(int);
        void insertatpos(int , int );
        void display();
};


void doublylinkedlist::insertbeg(int num){ // Time complexity is O(1)
    struct node * newnode = (struct node *) malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = head;
    newnode->data = num;
    head = newnode;
    count++;
}


void doublylinkedlist::insertatpos(int num , int pos){ // Time complexity is O(n)
    if (pos == 0 ){
        insertbeg(num);
    }
    else if (pos > count){
        printf("Can't insert here");
    }
    else if (pos ==1){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = num;
        newnode->prev = head;
        newnode->next = head->next;
        head->next = newnode;
        count++;
    }
    else{
        struct node * newnode = (struct node *) malloc(sizeof(node));
        struct node * tempnode = head;
        for (int i =0 ; i< pos -1 ; i++){
            tempnode = tempnode->next;
        }
        newnode->prev = tempnode;
        newnode->next = tempnode->next;
        newnode->data = num;
        tempnode->next = newnode;
        count++;
    }
}

void doublylinkedlist::display(){ // Time complexity is O(n)
    if (count ==0){
        printf("List empty");
    }
    else{
        struct node * tempnode = head;
        while (tempnode != NULL){
            printf("%d\t",tempnode->data);
            tempnode = tempnode->next;
        }
    }
}
