void reversePrint(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* ptr,*prev,*nxt;
    ptr=llist;
    prev=NULL;
    nxt=NULL;
    if(llist==NULL){
        return ;
    }
    while(ptr!=NULL){
        nxt=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=nxt;
    }
    
    while(prev!=NULL){
        printf("%d\n",prev->data);
        prev=prev->next;
    }
}