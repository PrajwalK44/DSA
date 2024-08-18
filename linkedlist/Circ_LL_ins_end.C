//insert at end
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node *insert_end_ll(struct node *start){
    int num;
    struct node *nn,*ptr;
    printf("\nEnter data");
    scanf("%d",&num);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr=start;
    while (ptr->next!=start)
    {   
        ptr=ptr->next;
    }
    ptr->next=nn;
    
    nn->next=start;
    return start;
    
}