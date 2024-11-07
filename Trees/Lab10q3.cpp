#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stack>
using namespace std;


class tree {
    public:
        struct node {
            char data;
            struct node* left=NULL;
            struct node* right=NULL;
        };
        struct node* root;
        struct node* p;
        tree() {
            root = NULL;
            p=NULL;
        }
        struct node * expressiontree(); // TC is O(n)
        void preorder(struct node * ); // TC is O(n)
        void inorder(struct node *); // TC is O(n)
        void postorder(struct node * ); // TC is O(n)
};

int main() {
    tree t1;
    string n;
    int choice;
    while (true) {
        printf("\n");
        printf("Enter your choice:\n");
        printf("1.Insert Postfix expression \n2. PreOrder\n3. PostOrder\n4. InOrder\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                t1.expressiontree();
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
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}


struct tree::node * tree::expressiontree(){
    string n;
    stack<tree::node*> s;
    printf("\nEnter postfix expression :");
    getline(cin,n);
    for (int i=0 ; i < n.length() ; i++){
        if (n[i] == '+' || n[i] =='-' || n[i] == '*' || n[i] == '/'){
            struct tree::node * newnode = (tree::node *) malloc(sizeof(struct tree::node));
            newnode->data = n[i];
            newnode->right = s.top();
            s.pop();
            newnode->left = s.top();
            s.pop();
            s.push(newnode);
        }
        else{
            struct tree::node * newnode = (tree::node *) malloc(sizeof(struct tree::node));
            newnode->data = n[i];
            newnode->left=NULL;
            newnode->right=NULL;
            s.push(newnode);
        } 
    }
    return s.top();
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
