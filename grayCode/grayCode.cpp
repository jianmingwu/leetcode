#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;

        v.push_back(0);

        for (int i = 0; i < n; ++i) {
            int t = 1 << i;
            for (int j = v.size() - 1; j >= 0; --j)
                v.push_back(v[j] + t);
        }

        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v;

    v = s.grayCode(2);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;

    return 0;
}
