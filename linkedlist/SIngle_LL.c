#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* start=NULL;

struct node* create_LL();
struct node* display_LL();

struct node* insert_beg_LL();
struct node* insert_end_LL();
struct node* insert_bef_LL();
struct node* insert_after_LL();

struct node* delete_beg_LL();
struct node* delete_end_LL();
struct node* delete_node_LL();
struct node* delete_after_LL();

struct node* search();
struct node* count();

int main(){
    int option;
    do{
        printf("\n---Main Menu-----");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert");
        printf("\n4. Delete");
        printf("\n5. Search");
        printf("\n6. Count");
        printf("\n7. Exit");
        printf("\nEnter your option- ");
        scanf("%d",&option);

        switch(option){
            case 1:
                start=create_LL();
                printf("Linked List created");
                break;
        
            case 2:
                start=display_LL();
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
                case 5:
                    start=search();
                    break;
                case 6:
                    start=count();
                    break;
        }
    }while(option!=7);
}

struct node* create_LL(){
    struct node* nn, *ptr;
    int val;
    printf("\nEnter -1 to end");
    printf("\nEnter Data ");
    scanf("%d",&val);
    while(val!=-1){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=val;
        if(start==NULL){
            nn->next=NULL;
            start=nn;
            
        }
    else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=nn;
            nn->next=NULL;
        }
        printf("\nEnter Data ");
        scanf("%d",&val);   
    }
    return start;
}

struct node* display_LL(){
    struct node* ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    return start;
} 

struct node* insert_beg_LL(){
    struct node* nn;
    int val;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data-");
    scanf("%d",&val);
    nn->data=val;
    if(start==NULL){
        nn->next=NULL;
        start=nn;
    }
    else{
        nn->next=start;
        start=nn;
    }
    return start;
}

struct node* insert_end_LL(){
    struct node* nn, *ptr;
    int val;
    nn = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data- ");
    scanf("%d", &val);
    nn->data = val;
    nn->next = NULL;

    if (start == NULL) {
        start = nn;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = nn;
    }
    return start;
}

struct node* insert_bef_LL(){
    struct node* nn, *ptr, *temp;
    nn = (struct node*)malloc(sizeof(struct node));
    int val, data;
    printf("\nEnter the value before which you want to insert the data: ");
    scanf("%d", &val);
    printf("\nEnter the data: ");
    scanf("%d", &data);

    nn->data = data;

    // Case: Insert before the first node
    if (start != NULL && start->data == val) {
        nn->next = start;
        start = nn;
        return start;
    }

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        temp = ptr;
        ptr = ptr->next;
    }

    // Value not found
    if (ptr == NULL) {
        printf("\nValue not found in the list.");
        free(nn);
        return start;
    }

    // Insert the new node before `ptr`
    temp->next = nn;
    nn->next = ptr;

    return start;
}


struct node* insert_after_LL(){
    struct node* nn, *ptr, *temp;
    nn=(struct node*)malloc(sizeof(struct node));
    int val,data;
    printf("\nEnter the value after which you want to insert the data");
    scanf("%d",&val);
    printf("\nEnter the data ");
    scanf("%d",&data);
    ptr=start;
    temp=start;
    nn->data=data;
    while(temp->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=nn;
    nn->next=ptr;
    return start;
}

struct node* delete_beg_LL(){
    struct node* ptr;
    ptr=start;

    if(start==NULL){
        printf("No Elements in the list");
    }
    else{
        start=start->next;
        free(ptr);
    }
    return start;
}

struct node* delete_end_LL(){
    struct node* ptr, *temp;
    ptr=start;
    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
    return start;
}

struct node* delete_node_LL(){
    struct node* ptr, *temp;
    int val;
    printf("\nEnter the node which you want to delete");
    scanf("%d",&val);
    ptr=start;
    //if the very first node is to be deleted
    if(ptr->data==val){
        start=delete_beg_LL();
        return start;
    }
    else{
        while(ptr->data!=val){
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        free(ptr);
        return start;
    }
    
}

struct node* delete_after_LL(){
    struct node* ptr, *temp;
    int val;
    printf("\nEnter the node after which you want to delete");
    scanf("%d",&val);
    ptr=temp=start;
    while(temp->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return start;
}

struct node* search(){
    struct node* ptr;
    int val;
    int c=0;
    printf("\nEnter the element you want to search");
    scanf("%d",&val);
    ptr=start;
    while(ptr!=NULL){
        c++;
        if(ptr->data==val){
            printf("Value found at %d",c);
            break;
        }
        else{
            ptr=ptr->next;
        }
    }
    return start;
}

struct node* count(){
    struct node* ptr;
    int c=0;
    ptr=start;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    printf("The total number of nodes are %d",c);
    return start;
}

