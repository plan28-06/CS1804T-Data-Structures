#include<iostream>
#include<stdio.h>
using namespace std;
#define SIZE 6

class priority{
    public:
    int arr[SIZE];
    int cur,temp;
    priority()
    {
        cur=1;
    }
    void insert(int); // Function to insert elements - O(log n)
    void display(); // Function to display elements - O(n)
    void siftup(int *); // Function to preserve max heap condition - O(log n) [leaf to root when inserting]
    void siftdown(int *); // Function to preserve max heap condition - O(log n) [root to leaf when deleting]
    bool search(int); // Function to search elements - O(n)
    int del(); // Function to delete element - O(log n)
    void sort(); // Function to sort elements - O(n)
};

void priority::insert(int num){  
    if(cur==SIZE-1){
        cout<<"Full"<<endl;
    }
    else{
        arr[cur] = num;
        cur++;
        printf("Element Inserted Successfully\n");
        siftup(arr);
    }
};

void priority::siftup(int *arr) {
    int index = cur - 1;
    while (index > 1) {
        int parent = index / 2;
        if (arr[index] > arr[parent]) {
            int temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;
            index = parent;
        } else {
            break;
        }
    }
    printf("\nElement Sorted");
    return ;
}

void priority::display(){
    if (cur == 1){
        printf("No elements to display\n");
        return;
    }
    for (int i = 1; i < cur; i++){
        printf("%d\t" , arr[i]);
    }
    printf("\n");
;}


int priority::del(){
    if (cur == 1){
        printf("There are no elements in the Heap. Insert some to delete.\n");
        return 0;
    } else {
        int maxValue = arr[1];
        arr[1] = arr[cur - 1];
        cur--;
        siftdown(arr); // Restore Max-Heap property
        return maxValue;
    }
}


void priority::siftdown(int *arr) {
    int i = 1;
    while (true) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left < cur && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < cur && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

bool priority::search(int data){
    for (int i = 1; i < cur; i++){
        if (arr[i] == data){
            printf("Element Present\n");
            return true;
        }
    }
    return false;
}

void priority::sort() {
    printf("Sorted elements: ");
    while (cur > 1) {
        printf("%d ", del());
    }
    printf("\nThis is the List in descending order as it is a Max-Heap.\n");
}

int main(){
    priority l1;
    while (1){
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
            int a = l1.del();
            printf("Deleted Element: %d\n", a);
        }
        else if (choice == 3){
            l1.display();
        }
        else if (choice == 4){
            int data;
            printf("Enter the element you wish to search for: ");
            scanf("%d", &data);
            if (!l1.search(data)) {
                printf("Element Not Found\n");
            }
        }
        else if (choice == 5){
            l1.sort();
        }
        else if (choice == 6){
            exit(0);
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }
}
