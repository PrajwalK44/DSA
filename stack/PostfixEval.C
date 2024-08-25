#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100

int st[MAX];
int top=-1;

float evaluatePS(char source[]);
void push(float exp);
float pop();

int main(){
    int fin;
    char source[100];
    printf("\nEnter Postfix expression");
    gets(source);
    fin=evaluatePS(source);
    printf("\nThe value of the postfix expression is-%d",fin);
    return 0;
}

float evaluatePS(char ans[]){
    int i=0;
    float val, op1, op2;
    while(ans[i]!='\0'){
        if(isdigit(ans[i])){
            push((float)(ans[i]-'0'));
        }
        else{
            op2=pop(); 
            op1=pop();
            switch (ans[i])
            {
            case '+':
                val=op1+op2;
                break;
            case '-':
                val=op1-op2;
                break;
            case '*':
                val=op1*op2;
                break;
            case '/':
                val=op1/op2;
                break;
            case '%':
                val=(int)op1%(int)op2;
                break;
            
            default:
                break;
            } 
            push(val); 
        }
        i++;
    }
    return st[top];
}

void push(float exp){
    if(top==MAX-1){
        printf("\nOverflow");
        exit(1);
    }
    else{
        top++;
        st[top]=exp;
    }
}

float pop(){
    float val;
    if(top==-1){
        printf("\nUnderflow");
        exit(1);
    }
    else{
        val=st[top];
        top--;
    }
    return val;
}