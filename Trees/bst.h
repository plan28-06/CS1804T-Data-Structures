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
        void insert_node(int);
        void inorder(struct node *,int *,int&);
};



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




void tree::inorder(struct node * p1,int * arr,int& index){
    if (p1)
    {
        inorder(p1->left,arr,index);
        arr[index++] = p1->data;
        inorder(p1->right,arr,index);
    }
}

