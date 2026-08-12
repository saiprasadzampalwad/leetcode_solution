/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    int flag=0;
    struct ListNode *i =(struct ListNode*)malloc(sizeof(struct ListNode));
    i->next=head;
    struct ListNode* j=head;
    while(j!=NULL)
     {  if (j->val != val) {
            i=i->next;
            i->val = j->val; 
            flag=1;
        }
        j=j->next;
    }
    if(flag==0)
    {
        return NULL;
    }
    i->next=NULL;
    return head;
}
