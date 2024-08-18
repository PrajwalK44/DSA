//create linked-list function
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node * create_LL(struct node *start){
    struct node *nn;
    int num;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter -1 to end");
    printf("Enter a number to insert");
    scanf("%d",&num);
    nn->data=num;
    if(start==NULL){
        nn->next=null;
        start=nn;
    }
    else{
        nn->next=start;
        start=nn;
    }
    return start;
}