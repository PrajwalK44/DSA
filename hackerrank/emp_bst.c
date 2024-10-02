#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int id;
    char name[20];
    struct node* left;
    struct node* right;
}*root=NULL;

struct node* insert(struct node* p, int val, char *name){
    struct node* nn, *ptr, *temp;

    nn=(struct node*)malloc(sizeof(struct node));
    nn->id=val;
    strcpy(nn->name, name);
    nn->left=NULL;
    nn->right=NULL;
    
    if(p==NULL){
        return nn;
    } 

    ptr=p;
    temp=NULL;

    //searching
    while(ptr!=NULL){
        temp=ptr;
        if(val < ptr->id){
            ptr=ptr->left;
        } else if (val > ptr->id){
            ptr=ptr->right;
        } 
    }

    //inserting
    if(val < temp->id){
        temp->left=nn;
    }
    else temp->right=nn;

    return p;
}
 
void inorder(struct node* p){
    if(p != NULL){
        inorder(p->left);
        printf("%d %s\n", p->id, p->name);
        inorder(p->right);
    }
}

struct node* minEle(struct node* p){
    if(p == NULL || p->left == NULL){
        return p;
    } else return minEle(p->left);
}

struct node* maxEle(struct node* p){
    if(p == NULL || p->right == NULL){
        return p;
    } else return maxEle(p->right);
}

int count(struct node* p){
    if(p == NULL){
        return 0;
    } else return (count(p->left) + count(p->right) + 1);
}

int main() {
    int id;
    char command[20];
    char name[20];
    
    while (scanf("%s", command) != EOF) { 
        if (strcmp("Insert", command) == 0) {
            scanf("%d %s", &id, name);
            root = insert(root, id, name);
        } else if (strcmp("InOrderTraversal", command) == 0) {
            inorder(root); 
        } else if (strcmp("FindMinEmployeeID", command) == 0) {
            struct node* minNode = minEle(root);
            if (minNode) {
                printf("Employee with minimum ID: %d %s\n", minNode->id, minNode->name);
            }
        } else if (strcmp("FindMaxEmployeeID", command) == 0) {
            struct node* maxNode = maxEle(root);
            if (maxNode) {
                printf("Employee with maximum ID: %d %s\n", maxNode->id, maxNode->name);
            }
        } else if (strcmp("CountEmployees", command) == 0) {
            int ck = count(root);
            printf("Total employees: %d\n", ck);
        }
    }

    return 0;
}
