class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        
        i = j = 0;
        
        while (j < n) {
            if (A[j] != elem)
                A[i++] = A[j++];
            else
                ++j;
        }
        
        if (n == 0)
            return 0;
        else
            return i;
    }
};
