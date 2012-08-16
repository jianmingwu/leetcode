#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int i, j, k, l;
        vector<vector<int> > vv;

        if (num.size() < 4)
            return vv;

        sort(num.begin(), num.end());

        for (i = 0; i < num.size() - 3; ++i) {
            for (j = i + 1; j < num.size() - 2; ++j) {
                l = num.size() - 1;
                for (k = j + 1; k < l; ++k) {
                    int t = num[i] + num[j] + num[k];

                    if (t + num[l] < target)
                        continue;

                    while (l > k && t + num[l] > target)
                        --l;

                    if (l == k)
                        continue;

                    if (t + num[l] == target) {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[k]);
                        v.push_back(num[l]);
                        vv.push_back(v);
                    }

                    while (k < l - 1 && num[k] == num[k + 1])
                       ++k;
                }

                while (j < num.size() - 2 && num[j] == num[j + 1])
                    ++j;
            }
            while (i < num.size() - 3 && num[i] == num[i + 1])
                ++i;
        }

        return vv;
    }
};

int main()
{
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    Solution s;
    vector<vector<int> > vv;

    vv = s.fourSum(v, 0);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }

        cout << endl;
    }


    return 0;
}
