#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int id;
    char name[10];
    struct node* left;
    struct node* right;
};

struct node* root=NULL;
void insert(struct node* root, int val, char *name);
void inorder(struct node* root);
struct node* minEle(struct node* root);
struct node* maxEle(struct node* root);
int count(struct node* root);    //total employees

int main() {
    
    int id;
    getchar();
    char command[20];
    char name[20];
    
    scanf("%d",command);
    
    if(strcmp("Insert",command)==0){
        scanf("%d",&id);
        getchar();
        scanf("%s",name);
        insert(root, id, name);
    } else if(strcmp("InOrderTraversal",command)==0){
        inorder(root);
    } else if(strcmp("FindMinEmployeeID",command)==0){
        root=minEle(root);
        printf("%d",root->id);
    } else if(strcmp("FindMaxEmployeeID",command)==0){
        root=maxEle(root);
        printf("%d",root->id);
    } else if(strcmp("CountEmployees",command)==0){
        int ck=count(root);
        printf("Total employees: %d",ck);
    }
    return 0;
}

void insert(struct node* root, int val, char *name){
    struct node* nn,*ptr, *temp;
    temp=NULL;
    ptr=root;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->id=val;
    nn->name=name;
    nn->left=NULL;
    nn->right=NULL;
    if(!root){
        nn=root;
        nn->left=NULL;
        nn->right=NULL;
    } else{
        while(ptr){
            temp=ptr;   
            if(val<ptr->id){
                ptr=ptr->left;
            } else if(val>ptr->id){
                ptr=ptr->right;
            }
        }
        if(val < temp->id){
            temp->left=nn;
        } else {
            temp->right=nn;
        }
    }
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%d %s\n", root->id, root->name); 
        inorder(root->right);
    }
}


struct node* minEle(struct node* root){
    if(root==NULL || root->left==NULL){
        return root;
    } else{
        return minEle(root->left);
    }
}

struct node* maxEle(struct node* root){
    if(root==NULL || root->right==NULL){
        return root;
    } else{
        return maxEle(root->right);
    }
}

int count(struct node* root){
    if(!root){
        return 0;
    } else{
        return (count(root->left) + count(root->right) +1);
    }
}
