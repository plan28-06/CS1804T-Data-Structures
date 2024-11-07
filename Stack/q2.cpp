#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include"stackusingll.h"
using namespace std;
int isoperator(char );

int main(){
    int ch;
    stackll operatorstack;
    stackll operandstack;
    string exp;
    string outputexp;
    string evalexp;
    int tempexp;
    while (1){
        printf("1. Enter infix expression\t 2. Convert to Postfix\t 3. Evaluate Postfix\t 4. Exit\n");
        cin >> ch;
        if (ch==1){
            std::cout << "Enter infix expression: ";
            getchar();
            getline(cin,exp);
        }
        else if (ch==2){
            for (int i = 0 ; i < exp.length() ; i++){
                if (isoperator(exp[i]) == 0){
                    outputexp = outputexp+ exp[i];
                }
                else{
                    if (operatorstack.isempty()){
                        operatorstack.push(std::string(1, exp[i]));
                    }
                    else{
                        if (exp[i] == '*' || exp[i] == '\\' || exp[i] == '%'){
                            int temp = 0;
                            while (temp != 1){
                                if (operatorstack.peek() == "*" || operatorstack.peek() == "\\" || operatorstack.peek() == "%"){
                                    outputexp = outputexp + operatorstack.pop();
                                }
                                else if  ((operatorstack.isempty() ==  1) || (!(operatorstack.peek() == "*" || operatorstack.peek() == "\\" || operatorstack.peek() == "%"))){
                                        operatorstack.push(std::string(1, exp[i]));
                                        temp =1;
                                }
                            }
                        }
                        else if (exp[i] == '+' || exp[i] == '-'){
                            int temp = 0;
                            printf("\nmeow\n");
                            while (temp != 1){
                                if (operatorstack.peek() == "*" || operatorstack.peek() == "\\" || operatorstack.peek() == "%"){
                                    outputexp = outputexp + operatorstack.pop();
                                }
                                if  ((operatorstack.isempty() ==  1) || (operatorstack.peek() == "+" || operatorstack.peek() == "-")){
                                    outputexp = outputexp + operatorstack.pop();
                                }
                                if  ((operatorstack.isempty() ==  1) || operatorstack.peek() == "=") {
                                    operatorstack.push(std::string(1, exp[i]));
                                    temp =1;
                                }
                            }
                        }
                        else{
                            int temp = 0;
                            while (temp!=1){
                                if (operatorstack.peek() == "*" || operatorstack.peek() == "\\" || operatorstack.peek() == "%"){
                                    outputexp = outputexp + operatorstack.pop();
                                }
                                else if  ((operatorstack.isempty() ==  1) || (operatorstack.peek() == "+" || operatorstack.peek() == "-")){
                                    outputexp = outputexp + operatorstack.pop();
                                }
                                else if  ((operatorstack.isempty() ==  1) || operatorstack.peek() == "=") {
                                    operatorstack.push(std::string(1, exp[i]));
                                    temp =1;
                                }
                            }
                        }
                    }
                }
            }
            while (operatorstack.isempty() == 0){
                outputexp = outputexp + operatorstack.pop();
            }
            std::cout << outputexp;
            std::cout << endl;
        }
        else if (ch == 3){
            int a,b;
            for (int i = 0 ; i < outputexp.length() ; i++){
                if (isoperator(outputexp[i]) == 0){
                    operandstack.push(std::string(1, outputexp[i]));
                }
                else{
                    if (outputexp[i] == '*'){
                        a=std::stoi(operandstack.pop());
                        b=std::stoi(operandstack.pop());
                        tempexp = b * a;
                        operandstack.push(std::to_string(tempexp));
                    }
                    else if (outputexp[i] == '+'){
                        a=std::stoi(operandstack.pop());
                        b=std::stoi(operandstack.pop());
                        tempexp = b+a;
                        operandstack.push(std::to_string(tempexp));
                    }
                    else if (outputexp[i] == '/'){
                        a=std::stoi(operandstack.pop());
                        b=std::stoi(operandstack.pop());
                        tempexp = b/a;
                        operandstack.push(std::to_string(tempexp));

                    }
                    else if (outputexp[i] == '%'){
                        a=std::stoi(operandstack.pop());
                        b=std::stoi(operandstack.pop());
                        tempexp = b%a;
                        operandstack.push(std::to_string(tempexp));
                    }
                    else if (outputexp[i] == '-'){
                        a=std::stoi(operandstack.pop());
                        b=std::stoi(operandstack.pop());
                        tempexp = b-a;
                        operandstack.push(std::to_string(tempexp));

                    }
                    else if (outputexp[i] == '='){
                        a=std::stoi(operandstack.pop());
                        b=std::stoi(operandstack.pop());
                        tempexp = (a = b);
                        operandstack.push(std::to_string(tempexp));
                    }
                }
            }
            while (operandstack.isempty() != 1){
                evalexp = evalexp + operandstack.pop();
            }
            std::cout << evalexp;
            std::cout<<endl;
        }
        else if (ch == 4){
            exit(1);
        }
        else{
            std::cout << "\nEnter a valid number";
        }
    }
}

int isoperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '\\' || c == '%' || c == '='){
        return 1;
    }
    else{
        return 0;
    }
}