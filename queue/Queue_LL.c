#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

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
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node *));
    
    else{
        nn->data=x;
        nn->next=NULL;
        if(front == NULL)
         //empty queue condition
        {
            front=rear=nn;
        }
        else{
            rear->next=nn;
            rear=nn;
        }
    }
}

int dequeue(){
    int x=-1;
    struct node *ptr;
    //Queue empty condition
    if(front==NULL){
        printf("Queue is Empty");
    }
    else{
        ptr=front;
        front=front->next;
        x=ptr->data;
        free(ptr);
    }
    return x;
}

int peek(){
    //Empty condition
    if(front==NULL){
        printf("Queue is empty");
    }
    else{
        return front->data;
    }
}

void display(){
    int i;
    struct node *ptr;
    ptr=front;
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
}
