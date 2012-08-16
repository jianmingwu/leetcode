#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > vv;
        int i, j;

        if (k == 1) {
            for (i = n; i > 0; --i) {
                vector<int> v;
                v.push_back(i);
                vv.push_back(v);
            }
            return vv;
        }

        for (i = n; i >= n - k; --i) {
            vector<vector<int> > vvi;
            vvi = combine(i - 1, k - 1);

            for (j = 0; j < vvi.size(); ++j) {
                vector<int> v(vvi[j]);
                v.push_back(i);
                vv.push_back(v);
            }
        }

        return vv;
    }
};

int main()
{
    vector<vector<int> > vv;
    Solution s;

    vv = s.combine(4, 2);

    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
