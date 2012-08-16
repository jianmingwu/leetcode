#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<vector<int> > > vv(2);
        int i, j, z;

        for (i = n; i > 0; --i) {
            vector<int> v;
            v.push_back(i);
            vv[0].push_back(v);
        }

        for (i = 1; i < k; ++i) {
            int cnt = i & 1;

            for (j = 0; j < vv[1 - cnt].size(); ++j) {
                for (z = vv[1 - cnt][j].back() + 1; z <= n; ++z) {
                    vector<int> v(vv[1 - cnt][j]);

                    v.push_back(z);
                    vv[cnt].push_back(v);
                }
            }
            
            vv[1 - cnt].clear();
        }

        return vv[(k - 1) & 1];
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
