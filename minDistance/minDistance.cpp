#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int> > vv;
        int i, j;

        if (len1 == 0 || len2 == 0)
            return max(len1, len2);

        for (i = 0; i < len2; ++i) {
            vector<int> v(len1);
            vv.push_back(v);
        }

        if (word1[0] == word2[0])
            vv[0][0] = 0;
        else
            vv[0][0] = 1;

        for (i = 1; i < len1; ++i) {
            if (word1[i] == word2[0])
                vv[0][i] = i;
            else
                vv[0][i] = vv[0][i - 1] + 1;
        }

        for (i = 1; i < len2; ++i) {
            if (word1[0] == word2[i])
                vv[i][0] = i;
            else
                vv[i][0] = vv[i - 1][0] + 1;
        }

        for (i = 1; i < len2; ++i) {
            for (j = 1; j < len1; ++j) {
                vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + 1;
                if (word1[j] == word2[i])
                    vv[i][j] = min(vv[i][j], vv[i - 1][j - 1]);
                else
                    vv[i][j] = min(vv[i][j], vv[i - 1][j - 1] + 1);
            }
        }

        return vv[len2 - 1][len1 - 1];
    }
};

int main()
{
    string s1("sea");
    string s2("eat");
    string s3("algorithm");
    string s4("altruistic");
    Solution s;

    cout << s.minDistance(s1, s2) << endl;
    cout << s.minDistance(s3, s4) << endl;
    return 0;
}
