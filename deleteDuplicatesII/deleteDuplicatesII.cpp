class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        ListNode *p, *q;
        
        if (head == NULL)
            return NULL;

        p = head;
        while (p != NULL) {
            v.push_back(p->val);
            p = p->next;
            if (p == NULL)
                break;
                
            if (p->val == v.back()) {
                while (p != NULL && p->val == v.back())
                    p = p->next;
                v.pop_back();
            }
        }
        
        if (v.size() == 0)
            return NULL;

        p = head;
        q = NULL;
        for (int i = 0; i < v.size(); ++i) {
            p->val = v[i];
            q = p;
            p = p->next;
        }
        
        q->next = NULL;
        
        return head;
    }
};        

