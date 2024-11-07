#include<stdio.h>
#include<iostream>
#include<stdlib.h>

class linkedlist{
    int count = 0;
    struct node {
    int data;
    struct node * next;
    };
    struct node * head;
    struct node * tail;
    public:
       linkedlist(){
            head = NULL;
            tail = NULL;
        }
        void insertascending(int);
        void merge(linkedlist& , linkedlist&);
        void display();

    private:
        void gethead();
};


void linkedlist::insertascending(int num){
    struct node * newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = num;
    struct node * tempnode = head;
    struct node * prevnode = head;

    if (count == 0){
        head = newnode;
        newnode->next = NULL;
    }
    else if (count ==1){
        if (tempnode->data >= newnode->data){
            newnode->next = tempnode;
            head = newnode;
        }
        else{
            newnode->next = NULL;
            tempnode->next = newnode;
        }
    }
    else{
        for (int i = 0 ; i < count ; i++){
            if (tempnode->data > newnode->data){
                if (i==0){
                    head = newnode;
                    newnode->next = tempnode;
                    break;
                }
                else{
                prevnode->next = newnode;
                newnode->next = tempnode;
                break;
                }
            } 
            else if (tempnode->data <= newnode->data){
                if (i == count-1){
                    tempnode->next = newnode;
                    newnode->next = NULL;
                    break;
                }
                else{
                    tempnode = tempnode->next;
                    if (i == 0){
                        prevnode = head;
                    }
                    else if (i>0){
                        prevnode = prevnode->next;
                    }
                }
            }
        }
    }
    count++;
}


void linkedlist::display(){
    if (count ==0){
        printf("List empty");
    }
    else{
        struct node * tempnode = head;
        for (int i = 0; i<count;i++){
            printf("%d\t", tempnode->data);
            if (tempnode-> next != NULL){
                tempnode = tempnode-> next;
            }
        }
    }
}



void linkedlist::merge(linkedlist& list2 , linkedlist& list3){
    struct node * tempnode1 = head;
    struct node * tempnode2 =list2.head;
    while (!(tempnode1 == NULL && tempnode2 == NULL)){
        if (tempnode1 == NULL){
            struct node * newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = tempnode2->data;
            newnode->next = NULL;
            tempnode2 = tempnode2->next;
            if (list3.count > 0 ){
                list3.tail->next = newnode;
                list3.tail = newnode; 
                list3.count++;
            }
            else{
                list3.tail = newnode;
                newnode->next = NULL;
                list3.head  = newnode;
                list3.count++;
            }
        }
        else if (tempnode2 == NULL){
            struct node * newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = tempnode1->data;
            newnode->next = NULL;
            tempnode1 = tempnode1->next;
            if (list3.count > 0 ){
                list3.tail->next = newnode;
                list3.tail = newnode;
                list3.count++;
            }
            else{
                list3.tail = newnode;
                newnode->next = NULL;
                list3.head  = newnode;
                list3.count++;
            }

        }
        else if (tempnode1->data < tempnode2->data){
            struct node * newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = tempnode1->data;
            newnode->next = NULL;
            tempnode1 = tempnode1->next;
            if (list3.count > 0 ){
                list3.tail->next = newnode;
                list3.tail = newnode;
                list3.count++;
            }
            else{
                list3.tail = newnode;
                newnode->next = NULL;
                list3.head  = newnode;
                list3.count++;
            }
        }
        else if (tempnode2->data < tempnode1->data){
            struct node * newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = tempnode2->data;
            newnode->next = NULL;
            tempnode2 = tempnode2->next;
            if (list3.count > 0 ){
                list3.tail->next = newnode;
                list3.tail = newnode;
                list3.count++;
            }
            else{
                list3.tail = newnode;
                newnode->next = NULL;
                list3.head  = newnode;
                list3.count++;
            }
            
        }
        else if (tempnode2->data == tempnode1->data){
            struct node * newnode1 = (struct node *)malloc(sizeof(struct node));
            struct node * newnode2 = (struct node *)malloc(sizeof(struct node));
            newnode1->data = tempnode1->data;
            newnode1->next = newnode2;
            newnode2->data = tempnode2->data;
            newnode2->next = NULL;
            tempnode1 = tempnode1->next;
            tempnode2 = tempnode2->next;

            if (list3.count == 0){
                list3.head = newnode1;
            }
            else{
                list3.tail->next = newnode1;
            }
            list3.tail = newnode2;
            list3.count = list3.count+2;

        }

    }
    printf("\n List Merged");
}