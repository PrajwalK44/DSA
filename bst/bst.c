#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;

struct node* InorderPredecessor(struct node* root);

struct node* search(struct node* root, int key){
    struct node* ptr;
    ptr=root;

    if(root==NULL){
        return NULL;
    }

    while(ptr!=NULL){
        if(key==ptr->data){
            return ptr;
        }
        
        else if(key<ptr->data){
            ptr=ptr->left;
        }

        else if(key>ptr->data){
            ptr=ptr->right;
        }
    }
    return NULL;
}

void insert( int key){
    struct node* ptr, *temp, *nn;
    ptr=root;

    //first node
    if(root==NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=key;
        nn->left=nn->right=NULL;
        root=nn;
        return;
    }

    while(ptr!=NULL){
        temp=ptr;
        if(ptr->data==key)
            return;
        
        else if(key < ptr->data){
            ptr=ptr->left;
        }
        else if(key > ptr->data){
            ptr=ptr->right;
        }
    }
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=key;
    nn->left=nn->right=NULL;
    
    if(nn->data < temp->data){
        temp->left=nn;
    }
    else if(nn->data > temp->data){
        temp->right=nn;
    }
}

void inorder(struct node* r){
    if(r){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}

void preorder(struct node* r){
    if(r){
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node* r){
    if(r){
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->data); 
    } 
}

struct node* delete_node(struct node* root, int val)
{
    struct node* iPre;
    if(!root){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL && root->data==val){
        free(root);
        return NULL;
    }
    //finding the node to be deleted
    if(val<root->data){
        root->left=delete_node(root->left, val);
    } 
    else if(val>root->data){
        root->right=delete_node(root->right, val);
    }
    //deletion of node 
    else{
        //finding the INORDER PREDECESSOR
        iPre=InorderPredecessor(root);
        root->data=iPre->data;
        root->left=delete_node(root->left, iPre->data);
    }
    return root;
}

struct node* InorderPredecessor(struct node* root){
    root=root->left; //enters the left subtree
    while(root->right!=NULL){
        root=root->right; //finding the max element (as ,max element from left subtree = inorder predecessor)
    }
    return root;
}

void main(){
    int val,data;
    do{
        printf("--MAIN MENU--\n");
        printf("1- Insert\n");
        printf("2- Search\n");
        printf("3- Inorder\n");
        printf("4- Delete\n");
        printf("5- Postorder\n");
        printf("6- EXIT\n");
        printf("Your choice: ");
        scanf("%d",&val);
        switch(val){
        case 1:
            printf("ENTER DATA TO BE ENTERED: ");
            scanf("%d",&data);
            insert(data);
            break;
        case 2:
            printf("\n Enter the value to be searched");
            scanf("%d",&data);
            struct node* found = search(root, data);
            if (found != NULL)
                printf("Value %d found in the tree\n", data);
            else
                printf("Value %d not found in the tree\n", data);
            break;

        case 3:
            inorder(root);
            break;
        
        case 4:
            printf("\nEnter the value to delete");
            scanf("%d",&val);
            delete_node(root, val);
            break;
        
       
        
        case 5:
            printf("THANK YOU\n");
        default:
            printf("END");
            break;
        }
    }while(val!=5);
}
