#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* start=NULL;

struct node* create_LL();
struct node* display();

struct node* insert_beg_LL();
struct node* insert_end_LL();
struct node* insert_bef_LL();
struct node* insert_after_LL();

struct node* delete_beg_LL();
struct node* delete_end_LL();
struct node* delete_node_LL();
struct node* delete_after_LL();

int main(){
    int option;
    do{
        printf("\n---Main Menu-----");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert");
        printf("\n4. Delete");
        printf("\n5. Search");
        printf("\nEnter your option- ");
        scanf("%d",&option);

        switch(option){
            case 1:
                start=create_LL();
                printf("Linked List created");
                break;
        
            case 2:
                start=display();
                break;
            
            case 3:
                {
                    int opt1;
                    do{
                        printf("\n1. Insert at the beginning");
                        printf("\n2. Insert at the end");
                        printf("\n3. Insert before a specified node");
                        printf("\n4. Insert after a specified node");
                        printf("\n5. Exit ");
                        printf("\nEnter your option- ");
                        scanf("%d",&opt1);
                        switch (opt1)
                        {
                        case 1:
                            start=insert_beg_LL();
                            break;
                        case 2:
                            start=insert_end_LL();
                            break;
                        
                        case 3:
                            start=insert_bef_LL();
                            break;
                        case 4:
                            start=insert_after_LL();
                            break;
                        case 5:
                            printf("..........");
                            break;
                        default:
                            break;
                        }
                    }while(opt1!=5);
                    
                }
                break;
                case 4:
                {
                    int opt2;
                    do{
                        printf("\n1. Delete at the beginning");
                        printf("\n2. Delete at the end");
                        printf("\n3. Delete a specified node");
                        printf("\n4. Delete after a specified node");
                        printf("\n5. Exit ");
                        printf("\nEnter your option- ");
                        scanf("%d",&opt2);
                        switch (opt2)
                        {
                        case 1:
                            start=delete_beg_LL();
                            break;
                        case 2:
                            start=delete_end_LL();
                            break;
                        
                        case 3:
                            start=delete_node_LL();
                            break;
                        case 4:
                            start=delete_after_LL();
                            break;
                        case 5:
                            printf("..........");
                            break;
                        default:
                            break;
                        }
                    }while(opt2!=5);
                }
                break;
                
        }
    }while(option!=5);
}

struct node* create_LL(){
    struct node* nn, *ptr;
    
    int val;
    printf("Enter -1 to end");
    printf("\nEnter data-");
    scanf("%d",&val);
    
    
    while(val!=-1){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=val;
        if(start==NULL){
            nn->next=nn;
            start=nn;
        }
    else{
        ptr=start;
        while(ptr->next!=start){
            ptr=ptr->next;    
        }
        ptr->next=nn;
        nn->next=start;
    }
        printf("\nEnter data-");
        scanf("%d",&val);
    }
    return start;
}

struct node* display(){
    struct node* ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
    return start;
}

//INSERT FUNCTIONS
struct node* insert_beg_LL(){
    struct node* nn, *ptr;
    int val;
    printf("Enter data");
    scanf("%d",&val);
    ptr=start;
    
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    if(start==NULL){
        nn->next=nn;;
        start=nn;
    }
    else{
        
        while(ptr->next!=start){
            ptr=ptr->next;
        }
        ptr->next=nn;
        nn->next=start;
        start=nn;
    }
    return start;
}

struct node* insert_end_LL(){
    struct node* nn, *ptr;
    ptr=start;
    nn=(struct node*)malloc(sizeof(struct node));
    int num;
    printf("\nEnter data");
    scanf("%d",&num);
    nn->data=num;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->next=start;
    return start;
}

struct node* insert_bef_LL(){
    struct node* nn,*ptr,*temp;
    nn=(struct node*)malloc(sizeof(struct node));
    ptr=start;
    int val, num;
    printf("\nEnter the value before which value needs to be inserted");
    scanf("%d",&val);
    printf("\nEnter the data");
    scanf("%d",&num);
    nn->data=num;
    
    while(ptr->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=nn;
    nn->next=ptr;
    
    return start;
}

struct node* insert_after_LL(){
    struct node* nn,*ptr,*temp;
    nn=(struct node*)malloc(sizeof(struct node));
    ptr=temp=start;
    int val, num;
    printf("\nEnter the value after which value needs to be inserted");
    scanf("%d",&val);
    printf("\nEnter the data");
    scanf("%d",&num);
    nn->data=num;
    nn->next=NULL;
    while(temp->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    nn->next=ptr;
    temp->next=nn;
    return start;
}

struct node* delete_beg_LL(){
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
         ptr = ptr -> next;
    ptr -> next = start -> next;
    free(start);
    start = ptr -> next;
    return start;
}

struct node* delete_end_LL(){
    struct node* ptr, *temp;
    ptr=start;
    while(ptr->next!=start){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=start;
    free(ptr);
    return start;
}

struct node* delete_node_LL(){
    struct node* ptr,*temp;
    int val;
    printf("Enter the node");
    scanf("%d",&val);
    ptr=temp=start;
    while(ptr->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return start;
}

struct node* delete_after_LL(){
    struct node* nn,*ptr,*temp;
    ptr=temp=start;
    int val;
    printf("Enter the value after which you want to delete");
    scanf("%d",&val);
    while(temp->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return start;
}
