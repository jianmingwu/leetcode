#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        string cs(s);
        int space = (nRows - 1) * 2;
        int k = 0;

        if (nRows == 1)
            return s;

        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; i + j < s.size(); j += space) {
                cs[k++] = s[i + j];
                
                if (i > 0 && i < nRows - 1) {
                    if (i + j + space - 2 * i < s.size())
                        cs[k++] = s[i + j + space - 2 * i];
                }
            }
        }

        return cs;
    }
};

int main()
{
    string str("PAYPALISHIRING");
    Solution s;

    cout << s.convert(str, 3) << endl;

    return 0;
}
