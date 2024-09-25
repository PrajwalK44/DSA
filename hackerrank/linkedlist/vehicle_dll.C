#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int id;
    struct node* next;
    struct node* prev;
};

struct DLL {
    struct node* head;
    struct node* tail;
    int count;
};

struct DLL* fleet;

struct node* createDLLNode(int id);
void initList();
void addAtEnd(int vehicleID);
void removeVehicle(int vehicleID);
void printForward();
void printBackward();
void count();

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // Consume the newline character after reading 'n'
    initList();
    char input[100];
    char command[20];
    int ID;
    
    while (n--) {
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s %d", command, &ID);
        
        if (strcmp(command, "ADD") == 0) {
            addAtEnd(ID);
        } else if (strcmp(command, "REMOVE") == 0) {
            removeVehicle(ID);
        } else if (strcmp(command, "PRINT_FORWARD") == 0) {
            printForward();
            printf("\n");
        } else if (strcmp(command, "PRINT_BACKWARD") == 0) {
            printBackward();
            printf("\n");
        } else if (strcmp(command, "COUNT") == 0) {
            count();
            printf("\n");
        }
    }
    return 0;
}

struct node* createDLLNode(int id) {
    struct node* newVeh = (struct node*)malloc(sizeof(struct node));
    newVeh->id = id;
    newVeh->prev = NULL;
    newVeh->next = NULL;
    return newVeh;
}

void initList() {
    fleet = (struct DLL*)malloc(sizeof(struct DLL));  // Allocate memory for fleet
    fleet->head = NULL;
    fleet->tail = NULL;
    fleet->count = 0;
}

void addAtEnd(int vehicleID) {
    struct node* newVeh = createDLLNode(vehicleID);
    if (fleet->head == NULL) {
        fleet->head = fleet->tail = newVeh;
    } else {
        fleet->tail->next = newVeh;
        newVeh->prev = fleet->tail;
        fleet->tail = newVeh;
    }
    fleet->count++;
}

void removeVehicle(int vehicleID) {
    struct node* current = fleet->head;
    
    while (current != NULL && current->id != vehicleID) {
        current = current->next;
    }
    
    if (current == NULL) {  // Vehicle not found
        printf("Vehicle %d not found.\n", vehicleID);
        return;
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        fleet->head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        fleet->tail = current->prev;
    }
    
    free(current);
    fleet->count--;
}

void printForward() {
    struct node* ptr = fleet->head;
    if (ptr == NULL) {
        printf("No vehicles on the road.");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->id);
        ptr = ptr->next;
    }
}

void printBackward() {
    struct node* ptr = fleet->tail;
    if (ptr == NULL) {
        printf("No vehicles on the road.");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->id);
        ptr = ptr->prev;
    }
}

void count() {
    printf("%d", fleet->count);
}
