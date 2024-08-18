#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int st[MAX];
int top=-1;

void push(int);
int pop();
int peek();
void display();

int main(){
    int option, val;
    do{
        printf("\n--MAIN MENU---");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\n Enter your choice-");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the value to be pushed on stack-");
                scanf("%d",&val);
                push(val);
                break;
            
            case 2:
                printf("\nDeleting");
                val=pop();
                if(val!=-1){
                    printf("The popped value is %d",val);
                }
                break;
            
            case 3:
                val=peek();
                if(val!=-1){
                    printf("The value present at the top of the stack is- %d",val);
                }
                break;
            
            case 4:
                display();
                break;

            case 5:
                printf("Thank You !!");
                break;
            
            default:
                printf("Invalid Option!!");
                break;
        }
    }while(option!=5);
}

void push(int val){
    if(top==MAX-1){
        printf("\nStack Overflow!!");
        
    }else{
        top++;
        st[top]=val;
    }
}

int pop(){
    int val;
    if(top==-1){
        printf("\nStack Underflow !!");
        return -1;
    }else{
        val=st[top];
        top--;
        return val;
    }
}

int peek(){
    if(top==-1){
        printf("\nStack is Empty");
        return -1;
    }
    else{
        return st[top];
    }
}

void display(){
    int i;
    if(top==-1){
        printf("\nEmpty Stack");
    }
    for(int i=top; i>=0; i--){
        printf("%d",st[i]);
        printf("\n");
    }
}