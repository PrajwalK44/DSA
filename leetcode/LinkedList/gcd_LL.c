/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* ptr, *temp,*nn;
    
    ptr=head;
    while(ptr->next!=NULL){
        nn=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp=ptr;
        ptr=ptr->next;
    
        int x=ptr->val;
        int y=temp->val;
        int res=GCD(x, y);
        nn->val=res;
        temp->next=nn;
        nn->next=ptr;
    }
    return head;
}

int GCD(int x, int y)
{
    int rem;
    rem = x%y;
    if(rem==0)
        return y;
    else
        return (GCD(y, rem));
}