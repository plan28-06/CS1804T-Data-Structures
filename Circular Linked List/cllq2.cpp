#include <stdio.h>
#include "circularll.h"

int main()
{
    circularlinkedlist l1;
    int time;
    int choice;
    printf("Insert fixed execution time for each process:");
    scanf("%d",&time);
    while (1){
        getchar();
        getchar();
        system("cls");
        printf("\n 1. Insert new Process\t\t2. Execute\t3. Display\t4. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        if (choice ==1){
            int processtime;
            printf("Enter the time it takes to complete the process:");
            scanf("%d",&processtime);
            l1.insertatend(processtime);
            printf("Inserted process :)");
        }
        else if (choice == 2){
            if (l1.count == 0){
                printf("Insert a process first");
            }
            else{
                struct circularlinkedlist::node* tempnode = l1.head;
                if (tempnode->data - time <= 0){
                    printf("Process Executed\n");
                    printf("Deleted element %d\n",tempnode->data);
                    l1.deleteatbeg();
                }
                else{
                    printf("Process was not completed(will do it at the end), moving on to the next one\n");
                    printf("Deleted element %d\n",tempnode->data);
                    tempnode->data = tempnode->data - time;
                    l1.insertatend(tempnode->data);
                    l1.deleteatbeg();
                }
            }
        }
        else if (choice == 3 ){
            l1.display();
        }
        else if (choice == 4 ){
            exit(1);
        }
        else{
            printf("\n Enter a valid number");
        }
    }
}