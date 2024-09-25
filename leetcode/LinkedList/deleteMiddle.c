/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    int counter=0, n=0;
    struct ListNode* ptr, *temp, *assistant;
    ptr=head;
    assistant=head;
    temp=head;

    if(head==NULL || head->next==NULL){
        free(head);
        return NULL;
    }
    while(assistant!=NULL){
        
        assistant=assistant->next;
        n++;
    }
    
    while(counter!=n/2 && ptr!=NULL){
        temp=ptr;
        ptr=ptr->next;
        counter++;
    }
    if(ptr){
        temp->next=ptr->next;
        free(ptr);
    }
        
    
    return head;
}


/** another approach */
struct ListNode* deleteMiddle(struct ListNode* head) {
    int counter=0, n=0;
    struct ListNode* slow, *temp, *fast;
    slow=head;
    fast=head;
    temp=head;

    if(head==NULL || head->next==NULL){
        free(head);
        return NULL;
    }
    
    while(fast && fast->next){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    temp->next=slow->next;
    free(slow);
    return head;

}