#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<assert.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct MyQueue {
    int size;
    Node* front;
    Node* rear;
} MyQueue;

MyQueue* MyQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void MyQueuePush(MyQueue** obj, int val) {
    MyQueue* queue = *obj;
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    if (queue->rear) {
        queue->rear->next = node;
        queue->rear = node;
    } else {
        queue->front = node;
        queue->rear = node;
    }
    queue->size++;
}

void MyQueuePop(MyQueue** obj) {
    MyQueue* queue = *obj;
    Node* tmp = queue->front;
    if (queue->size > 0 && tmp) {
        queue->front = queue->front->next;
        queue->size--;
        free(tmp);
    }
    if (queue->rear == tmp) {
        queue->rear = NULL;
    }
}

int MyQueueFront(MyQueue** obj) {
    MyQueue* queue = *obj;
    assert(queue->front);
    return queue->front->value;
}

int MyQueueRear(MyQueue** obj) {
    MyQueue* queue = *obj;
    assert(queue->rear);
    return queue->rear->value;
}

int MyQueueSize(MyQueue** obj) {
    return (*obj)->size;
}

typedef struct {
    MyQueue* queue;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue = MyQueueCreate();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    int size;
    MyQueuePush(&obj->queue, x);
    size = obj->queue->size;
    while (size-- > 1) {
        MyQueuePush(&obj->queue, MyQueueFront(&obj->queue));
        MyQueuePop(&obj->queue);
    }
}

int myStackPop(MyStack* obj) {
    int val = MyQueueFront(&obj->queue);
    MyQueuePop(&obj->queue);
    return val;
}

int myStackTop(MyStack* obj) {
    return MyQueueFront(&obj->queue);
}

bool myStackEmpty(MyStack* obj) {
    return obj->queue->size == 0;
}

void myStackFree(MyStack* obj) {
    if (obj) {
        while (obj->queue && obj->queue->front) {
            MyQueuePop(&obj->queue);
        }
        free(obj->queue);
        free(obj);
    }
}

int main() {
    MyStack* stack = myStackCreate();
    int choice, value;

    do {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                myStackPush(stack, value);
                printf("%d\n", value);
                break;

            case 2:
                if (myStackEmpty(stack)) {
                    printf("Stack is Empty\n");
                } else {
                    value = myStackPop(stack);
                    printf("%d\n", value);  // Removed leading space
                }
                break;

            case 3:
                if (myStackEmpty(stack)) {
                    printf("Stack is Empty\n");
                } else {
                    value = myStackTop(stack);
                    printf("%d\n", value);
                }
                break;

            case 4:
                myStackFree(stack);
                printf("\n");
                exit(0);
                break;

            
        }
    }while(choice!=4);

    return 0;
}
