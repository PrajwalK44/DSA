#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 10


int top=-1;
char st[MAX];

void push(char);
char pop();

int main(){
    int i;
    int flag=1;
    char exp[MAX];
    char temp;
    printf("\nEnter expression");
    gets(exp);
    for(i=0; i<strlen(exp); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==-1){
                flag=0;
            }
            else{
                temp=pop();

                if((exp[i]==')') && (temp=='{'|| temp=='[')){
                    flag=0;
                }
                if((exp[i]=='}') && (temp=='('|| temp=='[')){
                    flag=0;
                }
                if((exp[i]==']') && (temp=='('|| temp=='{')){
                    flag=0;
                }
            }
        }
    }
    if(top>=0){
        flag=0;
    }
    if(flag==1){
        printf("\nValid");
    }
    else{
        printf("\nInvalid");
    }
    return 0;
}

void push(char r){
    if(top==MAX-1){
        printf("\nOverflow");
    }
    else{
        top++;
        st[top]=r;
    }
}

char pop(){
    if(top==-1){
        printf("\nUnderflow");
        exit(1);
    }
    else{
        char val;
        val=st[top];
        top--;
        return val;
    }
}