#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int i, j, k;
        vector<vector<int> > vv;

        if (num.size() < 3)
            return vv;

        sort(num.begin(), num.end());

        for (i = 0; i < num.size() - 2; ++i) {
            k = num.size() - 1;
            for (j = i + 1; j < k; ++j) {
                int t = num[i] + num[j];

                if (t + num[k] < 0)
                    continue;

                while (k > j && t + num[k] > 0)
                    --k;

                if (k == j)
                    continue;

                if (t + num[k] == 0) {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    vv.push_back(v);
                }

                while (j < k - 1 && num[j] == num[j + 1])
                    ++j;
            }

            while (i < num.size() - 2 && num[i] == num[i + 1])
                ++i;
        }

        return vv;
    }
};

int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    Solution s;
    vector<vector<int> > vv;

    vv = s.threeSum(v);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }

        cout << endl;
    }


    return 0;
}
