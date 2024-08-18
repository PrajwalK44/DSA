//inserting before a specified node
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* insert_before_ll(struct node *start){
    struct node *nn,*ptr,*temp;
    int num, val;
    printf("\n Enter data");
    scanf("%d",&num);
    printf("\n Enter value before which you want to insert");
    scanf("%d",&val);
    nn->data=num;
    ptr=start;
    while(ptr->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=nn;
    nn->next=ptr;
    return start;
    
}

