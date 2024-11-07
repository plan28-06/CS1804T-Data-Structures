#include<iostream>
#include<stdio.h>
using namespace std;
#define SIZE 5

class seperatechaining{
    public:
        struct node {
            int data;
            struct node * next;
        };
        struct node * arr[SIZE];
        seperatechaining()
        {
            std::fill(arr, arr + SIZE, NULL);
        }
        void insert(int); // Time Complexity - O(l) where l is the size of the linked list 
        void search(int); // Time Complexity - O(l) where l is the size of the linked list 
        void del(int); //   Time Complexity - O(l) where l is the size of the linked list 
};

int main(){
    seperatechaining l1;
    while (1){
        system("clear");
        int choice;
        printf("\nThese are the Operations in the priority queue");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1){
            int data;
            printf("Enter your Data: ");
            scanf("%d", &data);
            l1.insert(data);
        }
        else if (choice == 2){
            int data;
            printf("\nEnter your Data: \n");
            scanf("%d", &data);
            l1.del(data);
        }
        else if (choice == 3){
            int data;
            printf("Enter the element you wish to search for: ");
            scanf("%d", &data);
            l1.search(data);
        }
        else if (choice == 4){
            exit(0);
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
        getchar();
        getchar();
    }
}


void seperatechaining::insert(int num){
    int index = num%5;
    struct node * newnode = (struct node *) malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data = num;
    if (arr[index] == NULL){
        arr[index] = newnode;
    }
    else{
        struct node * temp = arr[index];
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
    printf("\n Number inserted \n");
}

void seperatechaining::del(int num){
    int index = num%5;
    if (arr[index] == NULL){
        printf("\nThe number doesn't exist\n");
        return;
    }
    else{
        struct node * temp = arr[index];
        if (temp->data == num){
            arr[index] = temp->next;
            printf("Number Deleted\n");
            return;
        }
        while (temp->next != NULL) {
            if (temp->next->data == num) {
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

void seperatechaining::search(int num){
    int index = num%5;
    if (arr[index] == NULL){
        printf("\nThe number doesn't exist\n");
        return;
    }
    else{
        struct node * temp = arr[index];
        if (temp->data == num){
            printf("Number exists\n");
            return;
        }
        while (temp->next != NULL) {
            if (temp->next->data == num) {
                printf("Number exists\n");
                return;
            }
            temp = temp->next;
        }
        printf("\nNumber doesn't exist\n");
        return;
    }
}