#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int x, y, i, n;
        string s, s1, s5;

        s1.push_back('I');
        s1.push_back('X');
        s1.push_back('C');
        s1.push_back('M');

        s5.push_back('V');
        s5.push_back('L');
        s5.push_back('D');

        n = num;
        y = x = n / 1000;
        for (i = 0; i < x; ++i)
            s.push_back('M');

        int div = 100;
        int cnt = 2;

        for (int cnt = 2; cnt >= 0; --cnt) {
            n -= (div * 10) * y;
            y = x = n / div;
            div /= 10;

            if (x == 4 || x == 9) {
                s.push_back(s1[cnt]);
                if (x == 4)
                    s.push_back(s5[cnt]);
                else
                    s.push_back(s1[cnt + 1]);
            } else{
                if (x > 4) {
                    s.push_back(s5[cnt]);
                    x -= 5;
                }

                for (i = 0; i < x; ++i)
                    s.push_back(s1[cnt]);
            }
        }

        return s;
    }
};

int main() {
    Solution s;

    cout << s.intToRoman(2012) << endl;
    cout << s.intToRoman(1500) << endl;

    return 0;
}
