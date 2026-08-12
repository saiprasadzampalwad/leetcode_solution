/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
     {
        if (head == NULL || head->next == NULL) {
            return head;
        }
         struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
dummy->next=head;
        struct ListNode* current;
        current = dummy;
        while (current->next != NULL && current->next->next != NULL) {
            struct ListNode* first = current->next;
            struct ListNode* second = current->next->next;
            first->next = second->next;
            second->next = first;
            current->next = second;
            current = first;
        }
    
        struct ListNode* newHead =dummy->next;
        free(dummy);
        return newHead;
        }
