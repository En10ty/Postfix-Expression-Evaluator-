#include <iostream>
#include <string>
#include <vector>
#include "LinkedStack.h"
#include "Node.h"
#include "StackInterface.h"
#include <sstream>
#include <cmath>
using namespace std;

//Cedric Dortch
//Assignment 3
//Friday March 17

int main() {
    LinkedStack<int> stack; //stack
    string expression[100]; //array to place input in
    string input; // input

    //get input from user
    std::cout << "Enter the postfix expression, 1 token per line. Enter '-1' to terminate.\n";
    int count = 0; 
    for(int y = 0; y < 500; y++) {
        cin >> input;
        if (input == "-1") {
            break;
        }
        else { 
            expression[y] = input; //putting input into the array
            count++; //increment count
        }
    }
    


    //Evaluating the given postfix expression
    for(int i = 0; i < count; ++i) {
        
        //if exprssion is an operand
        if(expression[i] != "*" && expression[i] != "+" && expression[i] != "-" && expression[i] != "/") {
            stack.push(stoi(expression[i])); 
            cout << expression[i] << "\n"; 
        }
        
        else  {//if expression is an operator 
            int op2 = stack.peek();
            stack.pop();

            int op1 = stack.peek();
            stack.pop();
            cout << op1 << " " << op2 << "\n"; 

           if(expression[i] == "+") { //addition
                stack.push(op1+op2);
           }      

            if(expression[i] == "-") { //subtraction
                stack.push(op1-op2);
           } 

           if(expression[i] == "*") { //multiplecation
                stack.push(op1*op2);
           } 

           if(expression[i] == "/") { //division
                stack.push(floor(op1/op2));
           } 
        }

    }

    //outputting the result 
    for (int u = 0; u < count; ++u) {
        cout << expression[u] << " ";
    }

    //outputting the result 
    cout << "=\n"; 
    std::cout << stack.peek() << endl; 

}