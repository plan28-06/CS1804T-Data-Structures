#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

class tree {
    public:
        struct node {
            int data;
            struct node* left;
            struct node* right;
        };
        struct node* root;
        struct node* p;
        tree() {
            root = NULL;
            p=NULL;
        }
        void insert_node(int); // Time complexity is O(log n)
        void preorder(struct node * ); // TC is O(n)
        void inorder(struct node *);   // TC is O(n)
        void postorder(struct node * ); // TC is O(n)
        struct node * search(int n,struct node *); // Time complexity is O(log n)
};

int main() {
    tree t1;
    int choice;
    while (true) {
        printf("\n");
        printf("Enter your choice:\n");
        printf("1.Insert Elements\n2. PreOrder\n3. PostOrder\n4. InOrder\n5. Search\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int n;
                printf("\nEnter number to insert :");
                cin >> n;
                t1.insert_node(n);
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
                int n;
                printf("Enter number to search:");
                cin >> n;
                if (t1.search(n,t1.root)){
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

void tree::insert_node(int num) {
    if (root == NULL){
        struct node * t=(struct node *) malloc(sizeof(struct tree::node));
        t->left=t->right=NULL;
        t->data = num;
        root = t;
        return;
    }
    struct node * t=(struct node *) malloc(sizeof(struct tree::node));
    t->left=t->right=NULL;
    t->data = num;
    struct node * tail = NULL;
    p = root;
    while (p!= NULL){
        if (num> p->data){
            tail = p;
            p=p->right;
        }
        else{
            tail=p;
            p=p->left;
        }
    }
    if (tail->data > num){
        tail->left = t;
    }
    else{
        tail->right = t;
    }
    printf("\nInserted\n");
}


void tree::preorder(struct node * p1){
    if (p1)
    {
        printf("%d\t",p1->data);
        preorder(p1->left);
        preorder(p1->right);
    }
}


void tree::inorder(struct node * p1){
    if (p1)
    {
        inorder(p1->left);
        printf("%d\t",p1->data);
        inorder(p1->right);
    }
}

void tree::postorder(struct node * p1){
    if (p1)
    {
        postorder(p1->left);
        postorder(p1->right);
        printf("%d\t",p1->data);
    }
}


struct tree::node * tree::search(int n ,struct node *){
    p = root;
    while (p!= NULL){
        if (n > p->data){
            p=p->right;
        }
        else if (n==p->data)
        {
            printf("\nThe number is present\n");
            return p;
        }
        else{
            p=p->left;
        }
    }
    printf("\nNumber not present\n");
    return;
}

