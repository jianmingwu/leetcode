#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j;

        i = j = 0;
        while (j < n) {
            A[i++] = A[j++];
            while (A[j] == A[j - 1])
                ++j;
        }

        return i;
    }
};

int main()
{
    int a[] = {1, 1};
    Solution s;

    cout << s.removeDuplicates(a, 2) << endl;

    return 0;
}
