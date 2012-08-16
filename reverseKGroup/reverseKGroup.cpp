class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 1 || head == NULL)
            return head;
        
        ListNode *p, *q, *x;
        int i;
        p = q = head;
        for (i = 0; p != NULL && i < k - 2; ++i)
            p = p->next;
        
        if (p == NULL || p->next == NULL)
            return head;

        head = p->next;
        
        p->next = head->next;
        head->next = q;
        p = head;
        
        for (i = 0; i < k - 2; ++i) {
            x = p->next;
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = x;
        }
        
        while (q!= NULL) {
            x = q;
            for (i = 0; i < k; ++i) {
                x = x->next;
                if (x == NULL)
                    break;
            }
            
            if (x == NULL)
                break;
            
            p = q;
            q = q->next;
            
            for (i = 0; i < k - 1; ++i) {
                x = p->next;
                p->next = q->next;
                q->next = p->next->next;
                p->next->next = x;
            }
        }
        
        return head;
    }
};
