#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c;

        if (n == 1)
            return 1;

        while (n > 1) {
            c = a + b;
            a = b;
            b = c;

            --n;
        }

        return c;
    }
};

int main()
{
    Solution s;

    cout << s.climbStairs(5) << endl;
    return 0;
}
