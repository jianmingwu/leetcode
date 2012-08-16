#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p, *q, *x;
        int i, rots;

        if (head == NULL || m == n)
            return head;

        if (m == 1) {
            rots = n - m - 1;
            p = q = head;
            for (i = 0; i < rots; ++i)
                p = p->next;
            head = p->next;
            p->next = head->next;
            head->next = q;
            p = head;
        } else {
            rots = n - m;
            p = head;
            for (i = 0; i < m - 2; ++i)
                p = p->next;
            q = p->next;
        }

        for (i = 0; i < rots; ++i) {
            x = p->next;
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = x;
        }

        return head;
    }
};

int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = NULL;

    Solution s;
    ListNode *ret = s.reverseBetween(&l1, 1, 4);

    while (ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
