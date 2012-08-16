#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;

        if (s.size() == 1)
            return 1;

        string s1(s.begin() + 1, s.end());
        int num = numDecodings(s1);
        if (s[0] == '1' || (s[0] == '2' && s[1] < '7')) {
            string s2(s.begin() + 2, s.end());
            if (s2.size() == 0)
                num++;
            else
                num += numDecodings(s2);
        }

         return num;
    }
};

int main()
{
    string str("12");
    Solution s;

    cout << s.numDecodings(str) << endl;
    return 0;
}
