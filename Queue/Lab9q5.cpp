#include<stdio.h>
#include"stackusingll.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    stackll stack1;
    int length;
    string c;
    string outputstr = "Output :";
    cout << "Input a string: ";
    getline(cin,c);
    length = c.length();
    cout << length << endl ; 
    for (int i = 0 ; i< length ; i++){
        if (std::string(1,c[i]) != "+"){
            cout << c[i]<<endl;
            stack1.push(std::string(1,c[i]));
            continue;
        }
        else{
            if (stack1.isempty() == 0){
                stack1.pop();
                continue;
            }
            else{
                printf("\nWrong Expression :(\n");
                break;
            }
        }
    }


    if (stack1.isempty() == 1){
        cout << "\n The number of +'s is more than the number of other characters"<<endl;
    }
    else{
        printf("Yay");
        while (stack1.isempty() == 0){
            outputstr = outputstr + stack1.pop();
        }
        reverse(outputstr.begin(), outputstr.end()); // for reverseing outputstr , lazy to use for loop :)
        printf("%s",outputstr);
    }
}

/* Stack is the optimal ADT and linkedlist is the optimal data structure(we dont know the length of the input)
for this the time complexity of the operation will be O(n)*/