#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<int> vc(128);
        int val = 0, i;

        vc['I'] = 1;
        vc['V'] = 5;
        vc['X'] = 10;
        vc['L'] = 50;
        vc['C'] = 100;
        vc['D'] = 500;
        vc['M'] = 1000;

        i = 0;
        while (i < s.size()) {
            int cnt = 1;
            int tv = vc[s[i]];
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                ++cnt;
                ++i;
            }

            if (i == s.size() - 1 || vc[s[i + 1]] < tv)
                val += cnt * tv;
            else {
                ++i;
                val += vc[s[i]] - tv * cnt;
            }
            ++i;
        }

        return val;
    }
};

int main()
{
    string str("MMXII");
    Solution s;

    cout << s.romanToInt(str) << endl;

    return 0;
}
