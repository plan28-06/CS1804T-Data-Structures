#include<stdio.h>
#include<iostream>
#include<stdlib.h>


class doublylinkedlist{
    int count=0;
    struct node {
        struct node * prev;
        int data;
        struct node * next;
    };
    struct node * head; 
    public:
        doublylinkedlist(){
            head = NULL;
        }
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
    doublylinkedlist list1;
    int choice, num,pos;
    while(true){ 
        system("clear");
        printf("Enter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit\n");
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
            list1.insertatpos(num,pos);
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
            list1.deleteatpos(pos);
        }
        else if (choice == 7){
            printf("Enter number to search:");
            scanf("%d",&num);
            list1.search(num);
        }
        getchar();
        getchar();
        
    }
    return 0;
}


void doublylinkedlist::insertbeg(int num){ // Time complexity is O(1)
    struct node * newnode = (struct node *) malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = head;
    newnode->data = num;
    head = newnode;
    count++;
}

void doublylinkedlist::insertatend(int num){ // Time complexity is O(n)
    if (count ==1){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->prev = head;
        newnode->data = num;
        newnode->next = NULL;
        head->next = newnode;
        count++;
    }

    else if (count == 0){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        head = newnode;
        newnode->prev = NULL;
        newnode->data = num;
        newnode->next = NULL;
        count++;
    }
    else{
        struct node * newnode = (struct node *) malloc(sizeof(node));
        struct node * tempnode = head;
        for (int i =0 ; i < count - 1 ; i++){
            tempnode = tempnode->next;
        }
        newnode->data = num;
        newnode->prev = tempnode;
        tempnode->next = newnode;
        newnode->next = NULL;
        count++;
    }
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
        for (int i = 0; i<count;i++){
            printf("%d\t", tempnode->data);
            if (tempnode-> next != NULL){
                tempnode = tempnode-> next;
            }
        }
    }
}

void doublylinkedlist::deleteatbeg(){ // Time complexity is O(1)
    if (count ==0){
        printf("The list is empty\n");
    }
    else if (count ==1){
        int c = head->data;
        head = NULL;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
    else{
        int c = head->data;
        head = head->next;
        head->prev = NULL;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
}

void doublylinkedlist::deleteatend(){ // Time complexity is O(n)
    if (count ==0){
        printf("The list is empty\n");
    }
    else if (count ==1){
        int c = head->data;
        count--;
        head = NULL;
        printf("\n Deleted element is %d\n",c);
    }
    else if (count == 2){
        struct node * tempnode = head;
        int c = tempnode -> next -> data;
        tempnode->next = NULL;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
    else{
        struct node * tempnode = head;
        for (int i =0; i<count-2;i++){
            tempnode = tempnode->next;
        }
        int c = tempnode->next->data;
        tempnode->next =NULL;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
}

void doublylinkedlist::deleteatpos(int pos){ // Time complexity is O(n)
    if (count ==0){
        printf("List is empty");
    }

    else if (pos>count-1){
        printf("Can't Delete here");
    }
    else{
        if (pos == 0){
            deleteatbeg();
        }
        else if (pos ==1){
            struct node * tempnode = head;
            int c = tempnode->next->data;
            if (pos == count -1){
                tempnode->next = NULL;
            }
            else{
                tempnode->next->next->prev = tempnode;
                tempnode->next = tempnode->next->next;
            }
            count --;
            printf("\n Deleted element is %d\n",c);
        }
        else if (pos == 2){
            struct node * tempnode = head;
            tempnode = tempnode->next;
            int c = tempnode->next->data;
            count--;
            if (pos == count -1){
                tempnode->next = NULL;
            }
            else{
                tempnode->next->next->prev = tempnode;
                tempnode->next = tempnode->next->next;
            }
            printf("\n Deleted element is %d\n",c);
        }
        else{
            struct node * tempnode = head;
            for (int i =0; i<pos-1;i++){
                tempnode = tempnode->next;
            }
            int c = tempnode->next->data;
            if (pos == count -1){
                tempnode->next = NULL;
            }
            else{
                tempnode->next->next->prev = tempnode;
                tempnode->next = tempnode->next->next;
            }
            count--;
            printf("\n Deleted element is %d\n",c);
        }
    }
}

void doublylinkedlist::search(int num){ // Time complexity is O(n)
    struct node * tempnode = head;
    int i=0;
    if (count == 0){
        printf("\nList Empty\n");
    }
    else{
        while (tempnode != NULL){
            if (tempnode->data == num){
                i = 1;
                break;
            }
            else{
                tempnode = tempnode->next;
                continue;
            }
        }
        if (i==1){
            printf("The number has been found");
        }
        else{
            printf("The number has not been found");
        }
    }
}