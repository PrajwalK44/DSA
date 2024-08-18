//insertion at beginning

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * insert_beg_cll(struct node* start ){
    struct node *nn;
    int num;
    printf("\nEnter data");
    scanf("%d",&num);
    nn=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=start;
    nn->data=num;
    nn->next=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=nn;
    start=nn;
    return start;
}

