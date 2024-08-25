#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#define MAX 100

int st[MAX];
int top=-1;

void InfixToPostfix(char source[], char target[]);
void push(char r);
char pop();
int getPriority(char op);

int main(){
    char infix[100], postfix[100];
    printf("\nEnter Infix expression");
    gets(infix);
    strcpy(postfix, "");
    InfixToPostfix(infix, postfix);
    printf("\nThe postfix expression is-");
    printf("\n");
    puts(postfix);
    return 0;
}

void InfixToPostfix(char source[], char target[]){
    int i=0; 
    int j=0;
    char temp;
    strcpy(target, "");
    while(source[i]!='\0'){
        //first opening paranthesis
        if(source[i]=='('){
            push(source[i]);
            i++;
        }
        //closing paranthesis
        else if(source[i]==')'){
            while((top!=-1) && (st[top]!='(')){
                target[j]=pop();
                j++;
            }
            if(top==-1){
                printf("\nInvalid Expression");
                exit(1);
            }
            //discarding remaning open paranthesis
            temp=pop();
            i++;
        }
        //If it is a character or num
        else if(isdigit(source[i])|| isalpha(source[i])){
            target[j]=source[i];
            j++;
            i++;
        }
        //it is a operator
        else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%'){
            while((top!=-1)&&(st[top]!='(')&& getPriority(st[top])>=getPriority(source[i])){
                target[j]=pop();
                j++;
            }
            push(source[i]);
            i++;
        }
        //If invalid exp
        else{
            printf("\nIncorrect Expression");
            exit(1);
        }
    }
    //After this if there is still something in the stack
    while ((top!=-1)&&st[top]!='(')
    {
        target[j]=pop();
        j++;
    }
    target[j]='\0';
    
}

int getPriority(char op){
    if(op=='*'||op=='/'||op=='%'){
        return 1;
    }
    else if(op=='+'||op=='-'){
        return 0;
    }
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
    char val;
    if(top==-1){
        printf("\nUnderflow");
        
    }
    else{
        val=st[top];
        top--;
        return val;
    }
    
}