/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* addnode(int num,struct ListNode* head)
 {
    
    struct ListNode *nn=(struct ListNode*) malloc(sizeof(struct ListNode));
     nn->val=num;
     nn->next=NULL;
     if(head==NULL)
     {
        head=nn;

     }
     else{
        struct ListNode *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
     }
     return head;
 }
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
 struct ListNode *head=NULL;
 while(list1!=NULL && list2!=NULL)
 {
    if(list1->val < list2->val){
      head=addnode(list1->val,head);
        list1=list1->next;

    }
    else{
        head= addnode(list2->val,head);
        list2=list2->next;
    }

 }
 if(list1!=NULL)
 {
    while(list1!=NULL)
    {
       head= addnode(list1->val,head);
       list1=list1->next;
    }
   
 } 
 else{
     while(list2!=NULL)
    {
       head= addnode(list2->val,head);
        list2=list2->next;
   
    }
    
 } 
 return head;
}