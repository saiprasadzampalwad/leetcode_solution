/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *i,*j,*max;
    i=head;
    int temp;
    while(i!=NULL)
    {
        max=i;
        j=i->next;
        while(j!=NULL)
        {
            if(max->val>j->val)
            {
                max=j;
            }
            j=j->next;

        }
        printf("%d",max->val);
        if(max!=i)
     {
         temp=max->val;
        max->val=i->val;
        i->val=temp;
    }
        i=i->next;
    }
    return head;
}