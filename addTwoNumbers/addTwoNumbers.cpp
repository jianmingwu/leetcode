#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int c = 0;
        ListNode *pl, *p1, *p2, *ph, *pt;

        ph = pt = NULL;
        p1 = l1;
        p2 = l2;
        while (p1 || p2) {
            int va, vb;
            if (p1) {
                va = p1->val;
                p1 = p1->next;
            } else
                va = 0;

            if (p2) {
                vb = p2->val;
                p2 = p2->next;
            } else
                vb = 0;

            int val = va + vb + c;
            if (val >= 10) {
                val -= 10;
                c = 1;
            } else {
                c = 0;
            }

            pl = new ListNode(val);

            if (!ph) {
                ph = pt = pl;
            } else {
                pt->next = pl;
                pt = pl;
            }
        }

        if (c == 1) {
            pl = new ListNode(1);
            pt->next = pl;
            pt = pl;
        }

        return ph;
    }
};

int main()
{
    ListNode l1a(2), l1b(4), l1c(3);
    ListNode l2a(5), l2b(6), l2c(4);

    l1a.next = &l1b;
    l1b.next = &l1c;

    l2a.next = &l2b;
    l2b.next = &l2c;

    Solution s;
    ListNode *l;

    l = s.addTwoNumbers(&l1a, &l2a);

    while (l) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;

    return 0;
}
