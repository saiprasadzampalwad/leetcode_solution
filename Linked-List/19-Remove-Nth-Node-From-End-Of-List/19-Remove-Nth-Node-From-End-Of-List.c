/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
 struct ListNode *temp,*temp2;
 temp=head;
 int i=0;
 while(temp!=NULL)
 {
    temp=temp->next;
    i++;
 }
 temp=head;
 if(i==1&&n==1)
 {
    head=NULL;
 }
 else{
     for (int j=1;j<=i-n;j++)
 {
    temp2=temp;
    temp=temp->next;
 }
 printf("%d",temp->val);
 
 if(head==temp)
 {head=temp->next;}
 else
{
 temp2->next = temp->next;
}
 }
 return head;

}