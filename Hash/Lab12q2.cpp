#include<iostream>
#include<stdio.h>
using namespace std;
#define SIZE 8

class hashadt{
    public:
        int arr[SIZE];
        hashadt()
        {
            std::fill(arr, arr + SIZE, -1);
        }
        void insert(int); // Function to insert elements - O(n)
        void display(); // Function to display elements - O(n)
        void search(int); // Function to search elements - O(n)
        void del(int); // Function to delete element - O(n)
        int isfull();
        int isempty();
};

int main(){
    hashadt l1;
    while (1){
        system("clear");
        int choice;
        printf("\nThese are the Operations in the priority queue");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort\n6. Exit\n");
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
            l1.display();
        }
        else if (choice == 4){
            int data;
            printf("Enter the element you wish to search for: ");
            scanf("%d", &data);
            l1.search(data);
        }
        else if (choice == 5){
            exit(0);
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
        getchar();
        getchar();
    }
}


void hashadt::insert(int num){
    int index = num % 8;
    int newindex = index;
    int k = 1;
    if (isfull()){
        printf("\nArray is Full \n");
        return;
    }
    else if (arr[index] == -1) {
        arr[index] = num;
    }
    else{
        while (arr[newindex] != -1){
            newindex = (index+ k * k)%8;
            k+=1;
        }
        arr[newindex] = num;
    }
    printf("\n Number inserted \n");
}

void hashadt::display(){
    if (isempty()){
        printf("\nArray is empty\n");
    }
    else{
        for (int i =0 ; i < SIZE ; i++){
            printf("%d\t",arr[i]);
            printf("\n");
        }
    }
}

void hashadt::search(int num){
    if (isempty()){
        printf("\nArray is empty\n");
    }
    else{
        int index = num % 8;
        int newindex = index;
        int k=1;
        if (arr[index] == num){
            printf("\nNumber Present\n");
            return;
        }
        else{
            while (arr[newindex] != -1 and k<8 /* maximum number of probes*/){
                newindex = (index + (k * k )) % 8;
                k+=1;
                if (arr[newindex] == num){
                    printf("\nNumber Present\n");
                    return;
                }
            }
        }
        printf("\nNumber not present\n");
    }
}

int hashadt::isfull(){
    for (int i = 0 ; i < SIZE ; i++){
        if (arr[i] != -1){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int hashadt::isempty(){
    for (int i = 0 ; i < SIZE ; i++){
        if (arr[i] == -1){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

void hashadt::del(int num){
    int index = num % 8;
    int k =1;
    int found = 0;
    if (isempty()){
        printf("\nArray is empty\n");
        return;
    }
    else{
        for (int i = 0 ; i < SIZE ; i ++){
            if (arr[index] == num){
                found = 1;
                arr[index] = -1;
                printf("\nNumber deleted\n");
                return;
            }
            else{
                index = (index + k * k) % 8;
                k+=1;
            }
        }
        if (found != 1){
            printf("\nNumber not found\n");
        }
    }
}