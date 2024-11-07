#include<stdio.h>
#include"stackusingll.h"
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


int main(){
    stackll stack1;
    int length;
    string c;
    cout << "Input a string of paranthesis: ";
    getline(cin,c);
    length = c.length();
    for (int i = 0 ; i< length ; i++){
        if (c[i] == '('){
            stack1.push(std::string(1, c[i]));
            continue;
        }
        else{
            if (c[i] == ')'){
                if (stack1.isempty() == 0  && stack1.peek() =="(" ){
                    stack1.pop();
                    continue;
                }
                else{
                    printf("\nThe brackets are not balanced\n");
                    exit(1);
                }
            }
        }
    }
    if (stack1.isempty() == 1){
        printf("\nThe brackets are balanced\n");
    }
    else{
        printf("\nThe brackets are not balanced\n");
    }
}


// The time complexity is O(n), this solution using stack is the optimal solution 