#include<stdio.h>
#include<iostream>

class listadt{
    public:
        int arr[5]; // Initialize array
        int cur;
        listadt(){
            cur = -1;
        };
        void insertbeg(int);
        void insertatend(int);
        void display();
        void insertatpos(int , int );
        void deleteatbeg();
        void deleteatend();
        void deleteatpos(int);
        void search(int);
};

int main(){
    int choice, num,pos;
    listadt list1;
    while(true){  // Display loop
        system("clear");
        printf("Enter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        if (choice ==1){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.insertbeg(num);
        }
        else if (choice == 8){
            list1.display();
        }
        else if (choice == 2){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.insertatend(num);
        }
        else if (choice == 9 ){
            exit(1);
        }
        else if (choice == 3){
            printf("Enter number to insert:");
            scanf("%d",&num);
            printf("Enter index to insert at:");
            scanf("%d",&pos);
            list1.insertatpos(pos,num);
        }
        else if (choice == 4){
            list1.deleteatbeg();
        }
        else if (choice == 5){
            list1.deleteatend();
        }
        else if (choice == 6){
            printf("Enter index to delete from:");
            scanf("%d",&pos);
            list1.insertatpos(pos,num);
        }
        else if (choice == 7){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.search(num);
        }
        getchar();
        getchar();
        
    }
    return 0;
};

void listadt::insertbeg(int num){ // Insert at beginning
    if (cur == 4){
        printf("The list is full\n");
    }
    else if (cur == -1 ){
        arr[0] = num;
        cur++;
        printf("Number %d inserted beginning\n",num);
    }
    else{
        for (int i = cur ; i >= 0 ; i--){
           arr[i+1] = arr[i];
        }
        arr[0] = num;
        cur++;
        printf("\n %d \n",cur);
        printf("Number %d inserted at the beginning\n",num);
    }
}

void listadt::display(){ // Display list
    if (cur == -1){
        printf("\n");
        printf("Array Empty Saar");
    }
    else{ 
        printf("\n");
        for (int i = 0; i <= cur ; i++){
            printf("%d\t",arr[i]);
        }
    }
}

void listadt:: insertatend(int num){ // Insert at the end
    if (cur ==4){
        printf("Array full saar");
        return;
    }
    else{  
    arr[cur +1] = num;
    cur++;
    printf("Number %d inserted at the end\n",num);
    }
}

void listadt::insertatpos(int pos , int num){ // Insert at position
    if (cur == 4){
        printf("Array full saar");
    }
    else if (pos > 4){
        printf("Index out of range");
    }
    else if (pos <= cur){
        for (int i = cur ; cur >= pos ; i --){
            arr[i+1] = arr[i];
        }
        arr[pos] = num;
        cur++;
    }
    else if (pos == cur+1){
        arr[pos] == num;
        cur++;
    }
    else{
        printf("Cant insert here saar index should be less than or equal to %d",cur);
    }
}

void listadt::deleteatbeg(){ // Delete at beginning
    if (cur == -1){
        printf("Array is empty saar");
    }
    else if(cur == 0){
        cur = -1;
        printf("Deleted 1st number saar");
    }
    else{
        for (int i = 1 ; i <= cur ; i++){
            arr[i-1] = arr[i];
        }
        cur -- ;
        printf("Deleted 1st item saar");
    }
};

void listadt::deleteatend(){ // Delete at the end
    if (cur == -1){
        printf("Array is empty saar");
    }
    else{
        cur -- ;
        printf("Deleted last item saar");
    }
}

void listadt::deleteatpos(int pos){ // Delete at position
    if (cur == -1){
        printf("Array empty saar");
    }
    else if (pos > 4){
        printf("Index out of range");
    }
    else if (pos < cur){
        for (int i = pos + 1 ; pos <= cur ; i ++){
            arr[i-1] = arr[i];
        }
        cur--;
    }
    else if (pos == cur){
        cur--;
    }
    else{
        printf("Cant insert here saar index should be less than or equal to %d",cur);
    }
}

void listadt::search(int num){ // Search
    if (cur == -1){
        printf("\n");
        printf("Array Empty Saar");
    }
    else{ 
        printf("\n");
        for (int i = 0; i <= cur ; i++){
            if (arr[i] == num){
                printf("Number %d found",num);
                exit(1);
            }
            else{
                continue;
            }
        printf("Number %d not found",num);
        }
    }
}