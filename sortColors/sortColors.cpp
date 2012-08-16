class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p, q, i;
                    
        for (p = 0; p < n && A[p] == 0; ++p);
        for (q = n - 1; q >= 0 && A[q] == 2; --q);
        
        for (i = p; i <= q; ++i) {
            while (p < q && A[i] != 1) {
                if (A[i] == 0) {
                    A[i] = A[p];
                    A[p] = 0;
                    ++p;
                    while (p <= q && A[p] == 0)
                        ++p;
                }
                
                if (A[i] == 2) {
                    A[i] = A[q];
                    A[q] = 2;
                    --q;
                    while (q >= p && A[q] == 2)
                        --q;
                }
                
                if (i < p)
                    i = p;
            }
        }
        
        return;
    }
};
