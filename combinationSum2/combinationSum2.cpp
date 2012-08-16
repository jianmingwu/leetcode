#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int i, j, k;
        vector<vector<vector<int> > > vvv(target + 1);

        sort(num.begin(), num.end());

        for (i = 0; i < num.size(); ++i) {
            if (num[i] > target)
                continue;

            vector<int> v;
            v.push_back(num[i]);
            v.push_back(i);
            
            vvv[num[i]].push_back(v);

            while (i + 1< num.size() && num[i] == num[i + 1])
                ++i;
        }

        for (i = 1; i <= target; ++i) {
            if (vvv[i].size() > 0) {
                for (j = 0; j < vvv[i].size(); ++j) {
                    vector<int> v = vvv[i][j];
                    k = v.back() + 1;
                    v.pop_back();

                    for (; k < num.size() && i + num[k] <= target; ++k) {
                        vector<int> vv(v);
                        vv.push_back(num[k]);
                        vv.push_back(k);
                        vvv[i + num[k]].push_back(vv);

                        while (k + 1 < num.size() && num[k] == num[k + 1])
                            ++k;
                    }
                }
            }
        }

        for (i = 0; i < vvv[target].size(); ++i) {
            vvv[target][i].pop_back();
        }

        return vvv[target];
    }
};

int main()
{
    int a[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    vector<vector<int> > vv;

    vv = s.combinationSum2(v, 8);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j)
            cout << vv[i][j] << " ";
        cout << endl;
    }

    return 0;
}
