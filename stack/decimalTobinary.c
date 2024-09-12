

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

struct Node* push(int);
int pop();
struct Node* display();

int main(){
    int n;
    printf("\nEnter a Decimal number ");
    scanf("%d",&n);
    if(n==0){
        printf("%d",0);
    }
    while(n!=0){
        push(n%2);
        n/=2;
    }
    display();
}

struct Node* push(int x){
    struct Node*nn;
    nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=x;
    if(top==NULL){
        nn->next=NULL;
        top=nn;
    }
    else{
        nn->next=top;
        top=nn;
    }
    return top;
}

struct Node* display(){
    int i;
    while(top){
        printf("%d",top->data);
        top=top->next;
    }
    return top;
}
