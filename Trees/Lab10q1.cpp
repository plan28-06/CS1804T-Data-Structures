#include <stdio.h>
#include <stdlib.h>
#include "circular_arr.h"
#include<iostream>
using namespace std;

class tree {
public:
    Queue q;
    struct node* root;
    struct node* p;
    tree() {
        root = NULL;
        p=NULL;
    }
    struct node* insert_node(); // TC is O(n) [We are creating the entire tree here not just inserting a node]
    void preorder(struct node * ); // TC is O(n) 
    void inorder(struct node *); // TC is O(n)
    void postorder(struct node * ); // TC is O(n)
    int search(char,struct node *); // TC is O(n)
};

int main() {
    tree t1;
    int choice;
    while (true) {
        printf("\n");
        printf("Enter your choice:\n");
        printf("1. Create Tree and Insert Elements\n2. PreOrder\n3. PostOrder\n4. InOrder\n5. Search\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                t1.insert_node();
                break;
            case 2:
                t1.preorder(t1.root);
                break;
            case 3:
                t1.postorder(t1.root);
                break;
            case 4:
                t1.inorder(t1.root);
                break;
            case 5:
                char f;
                printf("Enter character to search:");
                cin >> f;
                if (t1.search(f,t1.root)){
                    printf("\nTrue\n");
                }
                else{
                    printf("\nFalse\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

struct node* tree::insert_node() {
    char rootelem;
    printf("Enter root element:\n");
    scanf(" %c", &rootelem);  
    struct node* firstnode = (struct node*) malloc(sizeof(node));
    firstnode->data = rootelem;
    firstnode->left = NULL;
    firstnode->right = NULL;
    root = firstnode;
    q.enqueue(root);
    while (! q.isempty()){
        p = q.dequeue();
        char leftchild;
        char rightchild;
        printf("Enter left child element of %c:\n",p->data);
        printf("; -- No child :( \n");
        cin >> leftchild;
        if (leftchild != ';')
        {
            struct node* newnode = (struct node*) malloc(sizeof(node));
            newnode->data = leftchild;
            newnode->left = NULL;
            newnode->right = NULL;
            p->left=newnode;
            q.enqueue(newnode);
        }
        printf("Enter right child element of %c:\n",p->data);
        printf("; -- No child :( \n");
        cin >> rightchild;
        if (rightchild != ';')
        {
            struct node* newnode = (struct node*) malloc(sizeof(node));
            newnode->data = rightchild;
            newnode->left = NULL;
            newnode->right = NULL;
            p->right=newnode;
            q.enqueue(newnode);
        }
    }
    return root;
}


void tree::preorder(struct node * p){
    if (p)
    {
        printf("%c\t",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}


void tree::inorder(struct node * p){
    if (p)
    {
        inorder(p->left);
        printf("%c\t",p->data);
        inorder(p->right);
    }
}

void tree::postorder(struct node * p){
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%c\t",p->data);
    }
}

int tree::search(char c ,struct node * p){
    if (p)
    {
        if (p->data == c ){
            return 1;
        }
        search(c,p->left);
        search(c,p->right);
    }
    else{
        return 0;
    }
}