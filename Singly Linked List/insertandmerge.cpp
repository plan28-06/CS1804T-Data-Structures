#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"insertandmerge.h"


int main(){
    linkedlist list1;
    linkedlist list2;
    linkedlist list3;
    int choice, num,pos;
    while(true){ 
        system("cls");
        printf("Enter \n1. Insert Ascending\n2. Insert Ascending (list-2)\n3. Merge\n4. Display 1\n5. Display 2\n6. Display 3");
        printf("\n7. Exit");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        if (choice ==1){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.insertascending(num);
        }
        else if (choice  == 2){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list2.insertascending(num);
        }
        else if (choice == 3){
            list1.merge(list2,list3);
        }
        else if (choice == 4){
            list1.display();
        }
        else if (choice ==5){
            list2.display();
        }
        else if (choice == 6){
            list3.display();
        }
        else if (choice == 7 ){
             exit(1);
        }
        else{
            printf("Invalid Choice");
        }
        getchar();
        getchar();
        
    }
    return 0;
}