#include<iostream>
#include<stdio.h>
using namespace std;
#define SIZE 4

class graph{
    public:
        int arr[SIZE][SIZE]={{0}};
        void insert(int,int); // Time Complexity - O(1) 
        void search(int , int); // Time Complexity - O(1) 
        void del(int , int); //   Time Complexity - O(1) 
        void display(); // Time Complexity - O(n2)
};

int main(){
    graph l1;
    while (1){
        system("clear");
        int choice;
        printf("\nThese are the Operations in the priority queue");
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
            l1.insert(data1,data2);
        }
        else if (choice == 2){
            int data1;
            printf("Enter your vertex 1: ");
            scanf("%d", &data1);
            int data2;
            printf("Enter your vertex 2: ");
            scanf("%d", &data2);
            l1.del(data1,data2);
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
            l1.display();
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

void graph::insert(int a,int b){
    arr[a][b] = 1;
    arr[b][a] = 1;
    printf("\nInserted\n");
}

void graph::del(int a,int b){
    arr[a][b] = 0;
    arr[b][a] = 0;
    printf("\nDeleted\n");
}

void graph::search(int a , int b){
    if (arr[a][b]==1){
        printf("\nElement Present");
    }
    else{
        printf("\nElement not present\n");
    }
}

void graph::display(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}