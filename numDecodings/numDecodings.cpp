#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        if (s.size() < 2)
            return s.size();

        int i = s.size() - 1;

        while (i > 0) {
            if (s[i] == '0' && s[i - 1] != '1' && s[i - 1] != '2')
               return 0;
            --i; 
        }

        vector<int> v(s.size() + 1);
        i = s.size() - 1;
        v[i + 1] = 1;
        if (s[i] == '0')
            v[i] = 0;
        else
            v[i] = 1;

        --i;
        while (i >= 0) {
            if (s[i] == '0')
                v[i] = 0;
            else if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))
                v[i] = v[i + 1] + v[i + 2];
            else
                v[i] = v[i + 1];

            --i;
        }

        return v[0];
    }
};

int main()
{
    string str("12");
    Solution s;

    cout << s.numDecodings(str) << endl;
    return 0;
}
