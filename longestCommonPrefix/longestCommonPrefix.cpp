#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        int l, i;

        if (n == 0) {
            string s;
            return s;
        }

        if (n == 1)
            return strs[0];

        for (l = 0; l < strs[0].size(); ++l) {
            bool match = true;
            for (i = 1; i < n; i ++) {
                if (strs[i - 1][l] != strs[i][l]) {
                    match = false;
                    break;
                }
            }

            if (match == false)
                break;
        }

        string s(strs[0].begin(), strs[0].begin() + l);
        return s;
    }        
};

int main() {
    string s1("abc");
    string s2("ab");
    vector<string> vs;
    Solution s;

    vs.push_back(s1);
    cout << s.longestCommonPrefix(vs) << endl;
    
    vs.push_back(s2);
    cout << s.longestCommonPrefix(vs) << endl;



    return 0;
}
