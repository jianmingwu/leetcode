#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int i, j;
        vector<vector<int> > vvi;
        vector<int>::iterator vi;

        sort(num.begin(), num.end());
        
        for (vi = num.begin(); vi != num.end() && *vi <= target; ++vi) {
            while (vi + 1 != num.end() && *vi == *(vi + 1))
                ++vi;

            if (*vi == target) {
                vector<int> v;
                v.push_back(*vi);

                vvi.push_back(v);
                return vvi;
            }

            if (*vi < target) {
                vector<vector<int> > vv;
                vector<int> vc(num.begin(), vi);

                vv = combinationSum2(vc, target - *vi);

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
