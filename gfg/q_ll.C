void push(struct Queue* q, int k)
{
    struct QNode *ptr;
    
    ptr=(struct Queue *)malloc(sizeof(struct Queue *));
    //if heap is full 
    if(ptr==NULL){
        printf("\n Queue is Full");
        return;
    }
    else{
        ptr->key=k;
        ptr->next=NULL;
        if(q->front == NULL)
         //empty queue condition
        {
            q->front=q->rear=ptr;
        }
        else{
            q->rear->next=ptr;
            q->rear=ptr;
        }
    }
}

// Function to remove a key from given queue q
void pop(struct Queue* q)
{
    int x=-1;
    struct QNode *ptr;
    //Queue empty condition
    if(q->front==NULL){
        
    }
    else{
        ptr=q->front;
        q->front=q->front->next;
        x=ptr->key;
        free(ptr);
    }
    return x;
}