class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p, *q;
        
        if (head == NULL || head->next == NULL)
            return head;
            
        p = q = head;
        p = head = head->next;
        
        q->next = p->next;
        p->next = q;
        
        p = q->next;
        while (p != NULL && p->next != NULL) {
            q->next = p->next;
            p->next = q->next->next;
            q->next->next = p;
            
            q = p;
            p = q->next;
        }
        
        return head;
    }
};
