#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vs;
        vector<string> vs1;
        int len = digits.size();
        int i, j;

        if (digits.size() == 0) {
            string s;
            vs.push_back(s);
            return vs;
        }

        string ss(digits.begin(), digits.end() - 1);
        vs1 = letterCombinations(ss);

        if (digits[len - 1] < '7') {
            for (i = 0; i < vs1.size(); ++i) {
                vector<string> s(3, vs1[i]);
                for (j = 0; j < 3; ++j) {
                    s[j].push_back((digits[len - 1] - '2') * 3 + j + 'a');
                    vs.push_back(s[j]);
                }
            }
        } else if (digits[len - 1] == '8') {
            for (i = 0; i < vs1.size(); ++i) {
                vector<string> s(3, vs1[i]);
                for (j = 0; j < 3; ++j) {
                    s[j].push_back((digits[len - 1] - '2') * 3 + j + 1 + 'a');
                    vs.push_back(s[j]);
                }
            }
        } else if (digits[len - 1] == '7') {
            for (i = 0; i < vs1.size(); ++i) {
                vector<string> s(4, vs1[i]);
                for (j = 0; j < 4; ++j) {
                    s[j].push_back((digits[len - 1] - '2') * 3 + j + 'a');
                    vs.push_back(s[j]);
                }
            }
        } else {
            for (i = 0; i < vs1.size(); ++i) {
                vector<string> s(4, vs1[i]);
                for (j = 0; j < 4; ++j) {
                    s[j].push_back((digits[len - 1] - '2') * 3 + j + 1 + 'a');
                    vs.push_back(s[j]);
                }
            }
        }

        return vs;
    }
};

int main() {
    string str("23");
    Solution s;
    vector<string> vs;

    vs = s.letterCombinations(str);
    for (int i = 0; i < vs.size(); ++i)
        cout << vs[i] << endl;

    return 0;
}
