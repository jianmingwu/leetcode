#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> vs(2);
        int i, j;

        vs[0] = "1";

        for (i = 1; i < n; ++i) {
            int pidx = (i - 1) & 1;
            for (j = 0; j < vs[pidx].size(); ++j) {
                int cnt = 1;

                while (j + 1 < vs[pidx].size() && vs[pidx][j] == vs[pidx][j + 1]) {
                    ++j;
                    ++cnt;
                }

                vs[1 - pidx].push_back('0' + cnt);
                vs[1 - pidx].push_back(vs[pidx][j]);
            }
            vs[pidx].clear();
        }

        return vs[(n - 1) & 1];
    }
};

int main()
{
    Solution s;

    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;

    return 0;
}
