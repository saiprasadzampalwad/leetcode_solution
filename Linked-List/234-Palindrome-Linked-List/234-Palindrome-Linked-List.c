/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
 }
 struct ListNode* copyList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* newHead = createNode(head->val);
    struct ListNode* curr = head->next;
    struct ListNode* newCurr = newHead;
    while (curr != NULL) {
        newCurr->next = createNode(curr->val);
        newCurr = newCurr->next;
        curr = curr->next;
    }
    return newHead;
}

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true;
    }
    // Create a copy of the list
    struct ListNode* copy = copyList(head);
    // Reverse the copied list
    struct ListNode* reversedCopy = reverseList(copy);

    // Compare the original list with the reversed copy
    struct ListNode* original = head;
    struct ListNode* reversed = reversedCopy;
    while (original != NULL && reversed != NULL) {
        if (original->val != reversed->val) {
            return false;
        }
        original = original->next;
        reversed = reversed->next;
    }
    return true;
}