#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int i, j;
        vector<vector<int> > vvi;
        vector<int>::iterator vi;

        sort(candidates.begin(), candidates.end());
        
        for (vi = candidates.begin(); vi != candidates.end() && *vi <= target; ++vi) {
            if (*vi == target) {
                vector<int> v;
                v.push_back(*vi);

                vvi.push_back(v);
                return vvi;
            }

            if (*vi < target) {
                vector<vector<int> > vv;
                vector<int> vc(candidates.begin(), vi + 1);

                vv = combinationSum(vc, target - *vi);

                for (j = 0; j < vv.size(); ++j) {
                    vector<int> v(vv[j]);
                    v.push_back(*vi);
                    vvi.push_back(v);
                }
            }
        }

        return vvi;
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
