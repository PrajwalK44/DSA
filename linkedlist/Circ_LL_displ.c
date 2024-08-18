//displaying circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* display_circ_LL(struct node *start){
    struct node *ptr;
    ptr=start;
    do{
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }while(ptr!=start);
    return start;
}

