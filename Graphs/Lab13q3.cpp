#include<iostream>
#include<stdio.h>
using namespace std;
#define SIZE 4

class graph{
    public:
        struct node {
            int data;
            struct node * next;
        };
        struct node * arr[SIZE];
        void insert(int,int); // Time Complexity - O(l) where l is the size of the linked list
        int search(int , int); // Time Complexity - O(l) where l is the size of the linked list
        void del(int , int); //   Time Complexity - O(l) where l is the size of the linked list
        void display(int); // Time Complexity - O(n * l) where n is the size of the array and l is the size of the linked list
        graph(){
            for (int i = 0; i < SIZE; i++) {
                arr[i] = NULL;
            }
        }
};

int main(){
    graph l1;
    while (1){
        int choice;
        printf("\nThese are the Operations");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1){
            int data1;
            printf("Enter your vertex 1: ");
            scanf("%d", &data1);
            int data2;
            printf("Enter your vertex 2: ");
            scanf("%d", &data2);
            if (data1 == data2){
                l1.insert(data1,data2);
            }
            else{
                l1.insert(data1,data2);
                l1.insert(data2,data1);
            }
        }
        else if (choice == 2){
            int data1;
            printf("Enter your vertex 1: ");
            scanf("%d", &data1);
            int data2;
            printf("Enter your vertex 2: ");
            scanf("%d", &data2);
            if (data1 == data2){
                l1.del(data1,data2);
            }
            else{
                l1.del(data1,data2);
                l1.del(data2,data1);
            }
        }
        else if (choice == 3){
            int data1;
            printf("Enter your vertex 1: ");
            scanf("%d", &data1);
            int data2;
            printf("Enter your vertex 2: ");
            scanf("%d", &data2);
            l1.search(data1,data2);
        }
        else if (choice == 4){
            for (int i=0;i<SIZE;i++){
                l1.display(i);

            }
        }
        else if (choice==5){
            exit(1);
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
        getchar();
        getchar();
    }
    return 0;
}

void graph::insert(int a , int b){
    struct node * temp1 = arr[a];
    struct node * newnode = (struct node *) malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data = b;
    if (temp1 == NULL){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->next = NULL;
        newnode->data = b;
        arr[a] = newnode;
    }
    else{
        while (temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next = newnode;
    }
    return;
}

int graph::search(int a, int b) {
    if (arr[a] == NULL) {
        printf("Not Found\n");
        return 0; // Not found
    } else {
        struct node *temp = arr[a];
        while (temp != NULL) {
            if (temp->data == b) {
                printf("Found\n");
                return 1; // Found
            }
            temp = temp->next;
        }
    }
    printf("Not Found\n");
    return 0; // Not found
}

void graph::del(int a,int b){
    if (arr[a] == NULL){
        printf("\nThe number doesn't exist\n");
        return;
    }
    else{
        struct node * temp = arr[a];
        if (temp->data == b){
            arr[a] = temp->next;
            printf("Number Deleted\n");
            return;
        }
        while (temp->next != NULL) {
            if (temp->next->data == b) {
                temp->next = temp->next->next;
                printf("Number Deleted\n");
                return;
            }
            temp = temp->next;
        }
        printf("\nNumber doesn't exist\n");
        return;
    }
}

void graph::display(int a){
    struct node * temp = arr[a];
    if (temp==NULL){
        printf("NULL\n");
        return;
    }
    while (temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    if (temp==NULL){
        printf("NUll\n");
    }
}