#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string s_odd, s_even;
        vector<vector<int> > vv(2);
        int len, i, j, k, idx;
        int max_odd, max_even;

        if (s.size() == 0)
            return s_odd;

        // odd
        for (i = 0; i < s.size(); ++i)
            vv[0].push_back(i);

        len = 1;
        idx = 0;
        max_odd = 1;
        s_odd.assign(s, 0, 1);
        while (vv[idx].size() >= 1) {
            for (i = 0; i < vv[idx].size(); ++i) {
                int x = vv[idx][i] - len;
                int y = vv[idx][i] + len;
                if (x >= 0 && y < s.size() && s[x] == s[y])
                    vv[1 - idx].push_back(vv[idx][i]);
            }

            if (vv[1 - idx].size() == 1) {
                max_odd = len * 2 + 1;
                s_odd.clear();
                s_odd.assign(s, vv[1 - idx][0] - len, max_odd);
            }

            vv[idx].clear();
            ++len;
            idx = 1 - idx;
        }

        // even
        vv[0].clear();
        vv[1].clear();
        for (i = 0; i < s.size() - 1; ++i)
            if (s[i] == s[i + 1])
                vv[0].push_back(i);

        if (vv[0].size() == 0)
            return s_odd;

        len = 1;
        idx = 0;
        max_even = 2;
        s_even.assign(s, vv[0][0], 2);
        while (vv[idx].size() >= 1) {
            for (i = 0; i < vv[idx].size(); ++i) {
                int x = vv[idx][i] - len;
                int y = vv[idx][i] + 1 + len;
                if (x >= 0 && y < s.size() && s[x] == s[y])
                    vv[1 - idx].push_back(vv[idx][i]);
            }

            if (vv[1 - idx].size() == 1) {
                max_even = len * 2 + 2;
                s_even.clear();
                s_even.assign(s, vv[1 - idx][0] - len, max_even);
            }

            vv[idx].clear();
            ++len;
            idx = 1 - idx;
        }

        if (max_odd > max_even)
            return s_odd;
        else
            return s_even;

    }
};

int main() {
    string str("abcba");
    Solution s;

    cout << s.longestPalindrome(str) << endl;

    return 0;
}
