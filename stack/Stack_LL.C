#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));

    if(t==NULL){
        printf("Stack Overflow!!\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x=-1;
    struct node *t;
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        t=top;
        top=top->next;;
        x=t->data;
        free(t);
    }
    return x;
} 


void display(){
    struct node *p;
    p=top;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
        printf("\n");
    }
    
}

int peek(){
    if(top==NULL){
        printf("Stack is empty");
        return -1;
    }
    else{
        return top->data;
    }
}
 
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