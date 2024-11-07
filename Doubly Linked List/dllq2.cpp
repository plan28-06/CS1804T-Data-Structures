#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"dllq2.h"

int main(){
    doublylinkedlist list1;
    int choice,num;
    struct doublylinkedlist::node * temp = NULL;
    while(true){
        system("cls");
        printf("Enter \n1. Insert Webpage\n2. Front\n3. Back");
        printf("\n4. Display\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        if (choice == 4){
            list1.display();
        }
        else if (choice == 5 ){
            exit(1);
        }
        
        else if (choice == 1){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.insertatpos(num,list1.current+1);
            if (list1.count == 1){
                temp = list1.head;
            }
            else{
                if (list1.current+1 == list1.count-1){
                    temp = temp->next;
                }
                else{
                    temp = temp->next;
                    temp->next = NULL;
                    list1.display();
                    list1.count = list1.current + 1 ;
                }
            }
            list1.current++;
        }

        else if (choice == 2){
            if (temp == NULL){
                printf("No webpage open");
            }
            else if (temp->next == NULL){
                printf("Already in the last webpage");
            }
            else{
                temp = temp->next;
                list1.current++;
            }
        }
        else if (choice == 3){
            if (temp == NULL){
                printf("No webpage open");
            }
            else if (temp->prev == NULL){
                printf("Already in the first webpage");
            }
            else{
                temp = temp->prev;
                list1.current--;
            }
        }
        else{
            printf("\n Enter a proper choice");
        }
        getchar();
        getchar();
        
    }
    return 0;
}

