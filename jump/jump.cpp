#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int i, x, y, step;

        if (n <= 1)
            return 0;

        x = 0;
        y = A[0];
        step = 1;

        while (y < n - 1 && y != x) {
            int cm = y;
            for (i = x + 1; i <= y; ++i) {
                if (i + A[i] > cm)
                    cm = i + A[i];
            }
            x = y;
            y = cm;
            ++step;
        }

        if (y >= n - 1)
            return step;
        else
            return -1;

    }
};

int main()
{
    int a[] = {2, 3, 1, 1, 4};
    int b[] = {1, 2, 0, 1};

    Solution s;
    cout << s.jump(a, 5) << endl;
    cout << s.jump(b, 4) << endl;

    return 0;
}
