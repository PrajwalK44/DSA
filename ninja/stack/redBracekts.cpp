#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> stack;

    for (int i = 0; i < s.length(); i++) {
        
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            stack.push(s[i]);
        }
        else if (s[i] == ')') {
            
            bool operatorFound = false;
            
            
            while (!stack.empty() && stack.top() != '(') {
                char top = stack.top();
                stack.pop();
                
               
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;  //changed 
                }
            }
            
            
            if (!stack.empty()) {
                stack.pop();
            }
            

            if (!operatorFound) { //if operatorfound is not satisfied or remains false 
            //then it is having redundant brackets
                return true;
            }
        }
    }
    

    return false;
}

