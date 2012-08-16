class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p, *q;
        int cnt, i, n;
                    
        cnt = 0;
        p = head;
        while (p != NULL) {
            ++cnt;
            p = p->next;
        }
        
        if (cnt == 0 || k % cnt == 0)
            return head;
            
        n = cnt - k % cnt;
        p = q = head;
        for (i = 0; i < n - 1; ++i)
            p = p->next;
        
        head = p->next;
        p->next = NULL;
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = q;
        
        return head;
    }
};
