#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int i, j, k, x;
        int m = -1, ret;

        sort(num.begin(), num.end());

        for (i = 0; i < num.size() - 2; ++i) {
            k = num.size() - 1;
            for (j = i + 1; j < k; ++j) {
                int t = num[i] + num[j];

                if (t + num[k] == target) {
                    return target;
                }

                if (t + num[k] < target) {
                    x = target - t - num[k];
                    if (m == -1 || x < m) {
                        m = x;
                        ret = t + num[k];
                    }

                    continue;
                } else {
                    while (k > j && t + num[k] > target)
                        --k;

                    if (k == j) {
                        x = t + num[k + 1] - target;
                        if (m == -1 || x < m) {
                            m = x;
                            ret = t + num[k + 1];
                        }
                    } else {
                        x = target - t - num[k];
                        if (m == -1 || x < m) {
                            m = x;
                            ret = t + num[k];
                        }

                        x = t + num[k + 1] - target;
                        if (x < m) {
                            m = x;
                            ret = t + num[k + 1];
                        }
                    }
                
                }

                while (j < k - 1 && num[j] == num[j + 1])
                    ++j;
            }

            while (i < num.size() - 2 && num[i] == num[i + 1])
                ++i;
        }

        return ret;
    }
};

int main()
{
    int a[] = {-1, 2, 1, -4};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    Solution s;

    cout << s.threeSumClosest(v, 1) << endl;

    return 0;
}
