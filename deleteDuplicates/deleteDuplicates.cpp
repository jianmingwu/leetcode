class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *prev, *curr;
        
        if (head == NULL)
            return NULL;

        prev = head;
        curr = prev->next;
        while (curr != NULL) {
            if (curr->val == prev->val) {
                prev->next = curr->next;
                delete curr;
            } else {
                prev = curr;
            }
            curr = prev->next;
        }
        
        return head;
    }
};
