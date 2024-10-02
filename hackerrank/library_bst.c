#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int isbn;
    struct node* left;
    struct node* right;
} *root = NULL;


struct node* insert(struct node* p, int val) {
    
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->isbn = val;
    nn->left = NULL;
    nn->right = NULL;

    //when no root is there
    if (p == NULL) {
        return nn;
    }

    struct node* ptr = p;  
    struct node* temp = NULL;  

    
    while (ptr != NULL) {
        temp = ptr;
        if (val < ptr->isbn) {
            ptr = ptr->left;  
        } else if (val > ptr->isbn) {
            ptr = ptr->right;  
        } 
    }

    if (val < temp->isbn) {
        temp->left = nn; 
    } else {
        temp->right = nn; 
    }

    return p; 
}


struct node* InPre(struct node* p) {
    while (p && p->right != NULL) {
        p = p->right;
    }
    return p;
}


struct node* delete(struct node* p, int val) {
    if (p == NULL) {
        return NULL;
    }

 
    if (val < p->isbn) {
        p->left = delete(p->left, val);
    } else if (val > p->isbn) {
        p->right = delete(p->right, val);
    } else {
        if (p->left == NULL && p->right == NULL) {
            free(p);
            printf("Book deleted\n");
            return NULL;
        }
        
        else if (p->left == NULL) { 
            struct node* temp = p->right;
            free(p);
            printf("\nBook deleted\n");
            return temp;
        } else if (p->right == NULL) { 
            struct node* temp = p->left;
            free(p);
            printf("\nBook deleted\n");
            return temp;
        }
    
        else {
            struct node* q = InPre(p->left);   
            p->isbn = q->isbn;
            p->left = delete(p->left, q->isbn);  
        }
    }

    return p;
}


void search(struct node* p, int val) {
    while (p != NULL) {
        if (val == p->isbn) {
            printf("Book found\n");
            return;
        } else if (val < p->isbn) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    printf("Book not found\n");
}


int smallest(struct node* p) {
    if (p == NULL) {
        printf("No books in the system\n");
        return 0;
    }

    while (p->left != NULL) {
        p = p->left;
    }

    return p->isbn;
    
}

int largest(struct node* p) {
    if (p == NULL) {
        printf("No books in the system\n");
        return 0;
    }

    while (p->right != NULL) {
        p = p->right;
    }
    return p->isbn;
}


void inorder(struct node* p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->isbn);
        inorder(p->right);
    } else if(root==NULL){
        printf("No books in the system\n");
        return;
    }
}

int main() {
    int min, max;
    int count;
    int isbn;
    char input[100];

    scanf("%d", &count);
    while (count--) {
        scanf("%s", input);
        if (strcmp("insert", input) == 0) {
            scanf("%d", &isbn);
            root = insert(root, isbn);
        } else if (strcmp("search", input) == 0) {
            scanf("%d", &isbn);
            search(root, isbn);
        } else if (strcmp("delete", input) == 0) {
            scanf("%d", &isbn);
            root = delete(root, isbn); 
        } else if (strcmp("min", input) == 0) {
            min = smallest(root);
            if(min!=0)
              printf("%d\n", min);
        } else if (strcmp("max", input) == 0) {
            max = largest(root);
            if(max!=0)
              printf("%d\n", max);
        } else if (strcmp("inorder", input)==0){
            inorder(root);
        }
    }
    return 0;
}
