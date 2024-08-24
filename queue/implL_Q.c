#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int q[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
int peek();
void display();

int main(){
    int option, val;
    do{
        printf("\n--MAIN MENU---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. EXIT");
        printf("\n Enter your choice-");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the value -");
                scanf("%d",&val);
                enqueue(val);
                break;
            
            case 2:
                printf("\nDeleting");
                val=dequeue();
                if(val!=-1){
                    printf("The deleted value is %d",val);
                }
                break;
            
            case 3:
                val=peek();
                if(val!=-1){
                    printf("The frontmost value in the queue is - %d",val);
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

void enqueue(int x){
    if(rear==MAX-1){
        printf("Overflow !!");
    }
    // else if(front==-1 && rear==-1){
    //     front=rear=0;
    //     q[rear]=x;
    // }
    else{
        rear++;
        q[rear]=x;
    }

}

int dequeue(){
    if(front==-1 || front>rear){
        printf("Underflow");
        return -1;
    }
    else{
        int val;
        // val=q[front];
        front++;
        if(front>rear){
            front=rear=-1;
        }
        return val;
    }
}

int peek(){
    if(front==-1 || front>rear){
        printf("Queue is empty");
        return -1;
    }
    else{
        return q[front];
    }
}

void display(){
    int i;
    if(front==-1 || front>rear){
        printf("Queue is Empty");
    }
    else{
        for(i=front; i<=rear; i++){
            printf("\t%d",q[i]);
        }
    }
}
