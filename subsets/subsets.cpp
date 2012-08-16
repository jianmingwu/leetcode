#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n, i, j;
        vector<vector<int> > vvi;

        if (S.size() == 0)
            return vvi;

        sort(S.begin(), S.end());

        n = 1;
        for (i = 0; i < S.size(); ++i)
            n <<= 1;

        for (i = 0; i < n; ++i) {
            int m = i;
            vector<int> v;
            for (j = 0; j < S.size(); ++j) {
                if (m & 1)
                    v.push_back(S[j]);
                m >>= 1;
            }
            vvi.push_back(v);
        }

        return vvi;

    }
};

int main()
{
    int a[] = {1, 2, 3};
    vector<int> vi(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    vector<vector<int> > vvi;

    vvi = s.subsets(vi);
    for (int i = 0; i < vvi.size(); ++i) {
        for (int j = 0; j < vvi[i].size(); ++j)
            cout << vvi[i][j] << " ";
        cout << endl;
    }

    return 0;
}
