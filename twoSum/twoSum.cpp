#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> v(numbers.size());
        vector<int> w(numbers.begin(), numbers.end());
        vector<int> vi;
        int i, j;

        sort(w.begin(), w.end());
        for (i = 0; i < w.size(); ++i)
            v[i] = target - w[i];

        i = 0;
        j = v.size() - 1;

        while (i < j) {
            if (w[i] == v[j]) {
                int t = w[i];
                for (int k = 0; k < numbers.size(); ++k) {
                    if (numbers[k] == w[i] || numbers[k] == target - w[i])
                        vi.push_back(k + 1);
                }
                return vi;
            } else if (w[i] > v[j])
                --j;
            else
                ++i;
        }

        return vi;
    }
};

int main() {
    int a[] = {2, 7, 11, 15};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    vector<int> vi;

    vi = s.twoSum(v, 9);
    cout << vi[0] << " " << vi[1] << endl;

    return 0;
}
