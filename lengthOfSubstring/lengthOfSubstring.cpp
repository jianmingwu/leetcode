#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, i, j;
        vector<char> v(26, 0);

        i = 0;
        j = 0;
        while (j < s.size()) {
            if (v[s[j] - 'a'] == 1) {
                while (s[i] != s[j]) {
                    --v[s[i] - 'a'];
                    ++i;
                }

                ++i;
            } else {
                ++v[s[j] - 'a'];
            }

            if (j - i + 1 > maxlen)
                maxlen = j - i + 1;

            ++j;
        }

        return maxlen;
    }
};

int main() {
    string str1("abcabcbb");
    string str2("bbbbb");

    Solution s;
    cout << s.lengthOfLongestSubstring(str1) << endl;
    cout << s.lengthOfLongestSubstring(str2) << endl;

    return 0;
}
