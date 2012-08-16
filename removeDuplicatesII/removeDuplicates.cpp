#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j;

        if (n < 3)
            return n;

        i = j = 1;
        while (j < n) {
            A[i++] = A[j++];
            while (A[j] == A[i - 2])
                ++j;
        }

        return i;
    }
};

int main()
{
    int a[] = {1, 1, 1, 2, 2, 3};
    Solution s;

    cout << s.removeDuplicates(a, 6) << endl;

    return 0;
}
