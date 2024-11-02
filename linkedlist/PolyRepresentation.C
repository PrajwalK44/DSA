#include<stdio.h>
#include<stdlib.h>

struct node{
    int expo;
    int coeff;
    struct node* next;
};

struct node* start1=NULL;
struct node* start2=NULL;
struct node* start3=NULL;
struct node* start4=NULL;
struct node* last3=NULL;

struct node* create_poly(struct node*);
struct node* display_poly(struct node*);
struct node* add_poly(struct node*, struct node*, struct node*);
struct node* sub_poly(struct node*, struct node*, struct node*);
struct node* add_node(struct node*, int, int);

int main(){
    int opt;
    do{
        printf("\n******* MAIN MENU *******");
        printf("\n 1. Enter the first polynomial");
        printf("\n 2. Display the first polynomial");
        printf("\n 3. Enter the second polynomial");
        printf("\n 4. Display the second polynomial");
        printf("\n 5. Add the polynomials");
        printf("\n 6. Display the result");
        printf("\n 7. Subtract the polynomials");
        printf("\n 8. Display the result");
        printf("\n 9. EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                start1=create_poly(start1);
                break;
            case 2:
                start1=display_poly(start1);
                break;
            case 3:
                start2=create_poly(start2);
                break;
            case 4:
                start2=display_poly(start2);
                break;
            case 5:
                start3=add_poly(start1, start2, start3);
                break;
            case 6:
                start3=display_poly(start3);
                break;
            case 7:
                start4=sub_poly(start1, start2, start4);
                break;
            case 8:
                start4=display_poly(start4);
                break;
        }
    }while(opt!=9);
}

struct node* create_poly(struct node* start){
    struct node *nn, *ptr;
    int n, c;
    printf("\n Enter the exponent");
    scanf("%d",&n);
    printf("Enter the coefficient");
    scanf("%d",&c);
    while(n!=-1)
    {
        if(start==NULL){
            nn=(struct node*)malloc(sizeof(struct node));
            nn->expo=n;
            nn->coeff=c;
            nn->next=NULL;
            start=nn;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            nn=(struct node*)malloc(sizeof(struct node));
            nn->expo=n;
            nn->coeff=c;
            nn->next=NULL;
            ptr->next=nn;
        }
        printf("\n Enter the exponent");
        scanf("%d",&n);
        printf("\n Enter the coefficient");
        scanf("%d",&c);
    }
    return start;
}

struct node* display_poly(struct node* start)
{
    struct node* ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\n%dx%d\t",ptr->coeff,ptr->expo);
        ptr=ptr->next;
    }
    return start;
}

struct node* add_poly(struct node *start1, struct node *start2, struct node *start3){
    struct node *ptr1, *ptr2;
    int sum_num;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo){
            sum_num=ptr1->coeff+ptr2->coeff;
            start3=add_node(start3, sum_num, ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        else if(ptr1->expo > ptr2->expo){
            start3=add_node(start3, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo){
            start3=add_node(start3, ptr2->coeff, ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL){
        while(ptr1!=NULL){
            start3=add_node(start3, ptr2->coeff, ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    if(ptr2==NULL){
        while(ptr1!=NULL){
            start3=add_node(start3, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->next;
        }
    }
    return start3;
}

struct node* sub_poly(struct node *start1, struct node *start2, struct node *start4){
    struct node *ptr1, *ptr2;
    int sub_num;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo){
            sub_num=ptr1->coeff-ptr2->coeff;
            start4=add_node(start4, sub_num, ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        else if(ptr1->expo > ptr2->expo){
            start4=add_node(start4, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo){
            start4=add_node(start4, ptr2->coeff, ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL){
        while(ptr1!=NULL){
            start4=add_node(start4, ptr2->coeff, ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    if(ptr2==NULL){
        while(ptr1!=NULL){
            start4=add_node(start4, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->next;
        }
    }
    return start4;
}

struct node* add_node(struct node* start, int c, int n){
    struct node* ptr, *nn;
    if(start==NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->expo=n;
        nn->coeff=c;
        nn->next=NULL;
        start=nn;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        nn=(struct node*)malloc(sizeof(struct node));
        nn->coeff=c;
        nn->next=NULL;
        nn->expo=n;
        ptr->next=nn;
    }
    return start;
}
