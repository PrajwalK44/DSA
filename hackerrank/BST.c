#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




struct node{
    int isbn;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;
struct node* tree=NULL;
struct node* InorderPredecessor(struct node* root);

void search(struct node* root, int key){
    struct node* ptr;
    ptr=root;

    if(root==NULL){
        printf("Book not found\n");
        return;
    }

    while(ptr!=NULL){
        if(key==ptr->isbn){
            printf("Book found\n");
            return;
        }
        
        else if(key<ptr->isbn){
            ptr=ptr->left;
        }

        else if(key>ptr->isbn){
            ptr=ptr->right;
        }
    }
    printf("Book not found\n");
    
}
void insert(int key){
    struct node* ptr, *temp, *nn;
    ptr=root;

    //first node
    if(root==NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->isbn=key;
        nn->left=nn->right=NULL;
        root=nn;
        return;
    }

    while(ptr!=NULL){
        temp=ptr;
        if(ptr->isbn==key)
            return;
        
        else if(key < ptr->isbn){
            ptr=ptr->left;
        }
        else if(key > ptr->isbn){
            ptr=ptr->right;
        }
    }
    nn=(struct node*)malloc(sizeof(struct node));
    nn->isbn=key;
    nn->left=nn->right=NULL;
    
    if(nn->isbn < temp->isbn){
        temp->left=nn;
    }
    else if(nn->isbn > temp->isbn){
        temp->right=nn;
    }
}


struct node* delete_node(struct node* root, int val)
{
    struct node* iPre;
    if(!root){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL && root->isbn==val){
        free(root);
        return NULL;
    }
    //finding the node to be deleted
    if(val<root->isbn){
        root->left=delete_node(root->left, val);
    } 
    else if(val>root->isbn){
        root->right=delete_node(root->right, val);
    }
    //deletion of node 
    else{
        //finding the INORDER PREDECESSOR
        iPre=InorderPredecessor(root);
        root->isbn=iPre->isbn;
        root->left=delete_node(root->left, iPre->isbn);
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

struct node *findSmallestElement(struct node *tree)
{
    if( (tree == NULL) || (tree->left == NULL))
        return tree;
    else
        return findSmallestElement(tree ->left);
}

 struct node *findLargestElement(struct node *tree)
 {
 if( (tree == NULL) || (tree->right == NULL))
  return tree;
 else
  return findLargestElement(tree->right);
 }

void inorder(struct node* r){
    if(r){
        inorder(r->left);
        printf("%d ",r->isbn);
        inorder(r->right);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    scanf("%d",&n);
    getchar();
    char input[100];
    char command[20];
    int Isbn;
    while(n--){
        fgets(input, sizeof(input), stdin);
        
        sscanf(input, "%s %d",command,&Isbn);
        
        if(strcmp(command, "insert")==0){
            insert(Isbn);
        } else if(strcmp(command, "delete")==0){
            delete_node(root, Isbn);
            printf("Book deleted\n");
        } else if(strcmp(command, "search")==0){
           search(root, Isbn);
        } else if(strcmp(command, "min")==0){
            tree=findSmallestElement(root);
            printf("%d\n",tree->isbn);
        } else if(strcmp(command, "max")==0){
            tree=findLargestElement(root);
            printf("%d\n",tree->isbn);
        }
         else if(strcmp(command, "inorder")==0){
            inorder(root);
        }
    }
    return 0;
}

