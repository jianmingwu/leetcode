#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int m, i;

        m = 0;
        for (i = 0; i <= m; ++i) {
            if (A[i] + i >= m) {
                m = A[i] + i;
                if (m >= n - 1)
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int a1[] = {2, 3, 1, 1, 4};
    int a2[] = {3, 2, 1, 0, 4};

    Solution s;
    cout << s.canJump(a1, 5) << endl;
    cout << s.canJump(a2, 5) << endl;

    return 0;
}
