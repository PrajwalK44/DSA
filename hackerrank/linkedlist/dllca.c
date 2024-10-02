#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1. add ok
//2. remove
//3. print_forward
//4. print_backward
//5. count

struct node {
    int id;
    struct node* next;
    struct node* prev;
}*start = NULL;


struct node* add(struct node* h, int val) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->id = val;
    nn->next = NULL;
    nn->prev = NULL;

    if (h == NULL) {
        return nn; 
    }

    struct node* ptr = h;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = nn;
    nn->prev = ptr;

    return h;
}

// Function to delete a node by its value
struct node* del(struct node* h, int val) {
    struct node* ptr = h;

    if (h == NULL) {
        printf("No Elements\n");
        return NULL;  // List is empty
    }

    while (ptr != NULL && ptr->id != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        return h;  // Value not found
    }

    // If the node is the head
    if (ptr == h) {
        h = h->next;
        if (h != NULL) {
            h->prev = NULL;
        }
    } else if (ptr->next == NULL) {  // If it's the last node
        ptr->prev->next = NULL;
    } else {  // If the node is in the middle
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
    return h;
}

struct node* print_forward(struct node* h) {
    struct node* ptr = h;
    while (ptr != NULL) {
        printf("%d ", ptr->id);
        ptr = ptr->next;
    }
    printf("\n");
    return h;
}


struct node* print_backward(struct node* h) {
    struct node* ptr = h;
    if (ptr == NULL) {
        return h;
    }

    // Traverse to the last node
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Print backward
    while (ptr != NULL) {
        printf("%d ", ptr->id);
        ptr = ptr->prev;
    }
    printf("\n");
    return h;
}

// Function to count the number of nodes
int count(struct node* h) {
    struct node* ptr = h;
    int ctt = 0;
    while (ptr != NULL) {
        ctt++;
        ptr = ptr->next;
    }
    return ctt;
}

int main() {
    int n, id;
    scanf("%d", &n);  // Number of commands
    char input[20];

    while (n--) {
        scanf("%s", input);  // Read the command

        if (strcmp("ADD", input) == 0) {
            scanf("%d", &id);
            start = add(start, id);
        }
        else if (strcmp("REMOVE", input) == 0) {
            scanf("%d", &id);
            start = del(start, id);
        }
        else if (strcmp("PRINT_FORWARD", input) == 0) {
            start = print_forward(start);
        }
        else if (strcmp("PRINT_BACKWARD", input) == 0) {
            start = print_backward(start);
        }
        else if (strcmp("COUNT", input) == 0) {
            int ck = count(start);
            printf("%d\n", ck);
        }
    }

    return 0;
}
