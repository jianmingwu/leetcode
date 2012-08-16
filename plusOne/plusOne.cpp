#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> v(digits.begin(), digits.end());
        int co = 1;
        int i = v.size() - 1;

        while (i >= 0 && co > 0) {
            v[i] += co;
            if (v[i] > 9) {
                co = 1;
                v[i] -= 10;
            } else
                co = 0;
            --i;
        }

        if (co == 1)
            v.insert(v.begin(), 1);

        return v;
    }
};

int main() {
    int a[] = {9, 9};
    vector<int> vi(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    vector<int> v;

    v = s.plusOne(vi);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
