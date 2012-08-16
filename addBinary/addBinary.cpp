#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s, t;
        int i, c, dif;

        dif = max(a.size(), b.size()) - min(a.size(), b.size());
        string pref(dif, '0');

        if (a.size() < b.size()) {
            t = b;
            s = pref + a;
        } else {
            t = a;
            s = pref + b;
        }

        c = 0;
        for (i = t.size() - 1; i >= 0; --i) {
            t[i] += c + s[i] - '0';
            if (t[i] >= '2') {
                c = 1;
                t[i] -= 2;
            } else {
                c = 0;
            }
        }

        if (c == 1) {
            t.insert(t.begin(), '1');
        }

        return t;
    }
};

int main()
{
    string a("11");
    string b("1");
    Solution s;

    cout << s.addBinary(a, b) << endl;

    return 0;
}
