#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;

int q[MAX];

void enqueue(int);
int dequeue();

void display();

int main(){
    int option, val;
    do{
        printf("\n--MAIN MENU---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. EXIT");
        printf("\n Enter your choice-");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the value -");
                scanf("%d",&val);
                enqueue(val);
                break;
            
            case 2:
              
                val=dequeue();
                if(val!=-1){
                    printf("The deleted value is %d",val);
                }
                break;
            
            
            
            case 3:
                display();
                break;

            case 4:
                printf("Thank You !!");
                break;
            
            default:
                printf("Invalid Option!!");
                break;
        }
    }while(option!=4);
}

void enqueue(int val){
    if((rear==MAX-1 && front==0)||rear+1==front){
        printf("\nOverflow");
        return;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
    }
    else if(rear==MAX-1 && front!=0){
        rear=0;
    }
    else{
        rear++;
    }
    q[rear]=val;
}

int dequeue(){
    int val;
    if(front==-1 && rear==-1){
        printf("\nUnderflow");
        return -1;
    }
    val=q[front];
    if(front==rear){
        front=rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
    return val;
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("\nEmpty Queue");
    }
    else{
        if(front<=rear){
            for(i=front;i<=rear;i++){
                printf("\t%d",q[i]);
            }
        }
        else{
            for(i=front; i<MAX; i++){
                printf("\t%d",q[i]);
            }
            for(i=0; i<=rear; i++){
                printf("\t%d",q[i]);
            }
        }
    }
    
}