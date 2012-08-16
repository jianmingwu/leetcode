#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int i, j, k;
        vector<vector<vector<int> > > vvv(target + 1);

        sort(candidates.begin(), candidates.end());

        for (i = 0; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                continue;

            vector<int> v;
            v.push_back(candidates[i]);
            v.push_back(i);
            
            vvv[candidates[i]].push_back(v);

            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                ++i;
        }

        for (i = 1; i <= target; ++i) {
            if (vvv[i].size() > 0) {
                for (j = 0; j < vvv[i].size(); ++j) {
                    vector<int> v = vvv[i][j];
                    k = v.back();
                    v.pop_back();

                    for (; k < candidates.size() && i + candidates[k] <= target; ++k) {
                        vector<int> vv(v);
                        vv.push_back(candidates[k]);
                        vv.push_back(k);
                        vvv[i + candidates[k]].push_back(vv);

                        while (k + 1 < candidates.size() && candidates[k] == candidates[k + 1])
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
    int a[] = {2, 3, 6, 7};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    vector<vector<int> > vv;

    vv = s.combinationSum(v, 7);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j)
            cout << vv[i][j] << " ";
        cout << endl;
    }

    return 0;
}
