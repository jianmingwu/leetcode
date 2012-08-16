class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p, *q;
        
        if (head == NULL)
            return NULL;

        p = q = head;
        for (int i = 0; i < n; ++i)
            p = p->next;
        
        if (p == NULL) {
            head = head->next;
            delete q;
            return head;
        }
        
        p = p->next;
        while (p != NULL) {
            p = p->next;
            q = q->next;
        }
        
        p = q->next;
        if (p != NULL) {
            q->next = p->next;
            delete p;
        }
        
        return head;
    }
};
