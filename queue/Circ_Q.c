#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;

int q[MAX];

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
    if((rear + 1) % MAX == front){
        printf("\nQueue is full\n");
        return; 
    }

    if(front == -1){  
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    q[rear] = x;
}

int dequeue(){
    if(front == -1){
        printf("\nUnderflow\n");
        return -1;
    }
    
    int val = q[front];
    if(front == rear){ 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

int peek(){
    if(front == -1){
        printf("Queue is Empty!!!\n");
        return -1;
    } else {
        return q[front];
    }
}


void display(){
    int i;
    printf("\n");
    if(front == -1){
        printf("Queue is Empty!!!\n");
    }
    else {
        printf("Queue elements are:");
        if(front <= rear){
            for(i = front; i <= rear; i++){
                printf("\t%d", q[i]);
            }
        }
        else{
            for(i = front; i < MAX; i++){
                printf("\t%d", q[i]);
            }
            for(i = 0; i <= rear; i++){
                printf("\t%d", q[i]);
            }
        }
        printf("\n");
    }
}