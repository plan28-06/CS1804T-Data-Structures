#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include"bst.h"
using namespace std;

int main(){
    tree t1;
    int noofele;
    int n;
    int findno;
    int index=0;
    printf("\nEnter number of elements : ");
    cin >> noofele;
    int arr[noofele];
    for (int i=0;i<noofele;i++){
        printf("\nEnter element to insert");
        cin >> n;
        t1.insert_node(n);
    }
    printf("\nEnter number whose previous smaller and next bigger number must be found : ");
    cin >> findno;
    t1.inorder(t1.root,arr,index);
    for (int i=0;i< noofele ;i++){
        if (arr[i]==findno){
            if (i==0){
                printf("\nNo smaller element\n");
                printf("The next bigger element is %d\n",arr[i-1]);
            }
            else if (i==noofele-1){
                printf("The prev smaller element is %d\n",arr[i-1]);
                printf("\nNo bigger element\n");
            }
            else{
                printf("The prev smaller element is %d\n",arr[i-1]);
                printf("The next bigger element is %d\n",arr[i+1]);
            }
        }
    }
}

// Here we are using a BST , firstly we get input from the user and then create the bst
// secondly we perform inorder and store it in an array (inorder in a bst returns the input in sorted order) 
// from the sorted array we find out the previous smaller and next bigger element
// TC is O(n)