#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            int len, i, j, t, mask;

            if (x < 0)
                return false;

            t = x;
            len = 0;
            while (t) {
                ++len;
                t /= 10;
            }
            
            mask = 1;
            for (i = 1; i < len; ++i)
                mask *= 10;

            i = 0;
            j = len - 1;
            t = x;

            while (i < j) {
                int l = t / mask;
                int r = t % 10;

                if (l != r)
                    return false;

                t = (t - l * mask - r) / 10;
                ++i;
                --j;
                mask /= 100;
            }

            return true;
        }
};

int main()
{
    Solution s;

    cout << s.isPalindrome(-10) << endl;
    return 0;
}
