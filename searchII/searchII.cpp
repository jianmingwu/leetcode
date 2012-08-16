class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hi, lo, mid, i;
        
        i = 0;
        while (i < n - 1) {
            if (A[i] <= A[i + 1])
                ++i;
            else
                break;
        }
        
        if (target > A[i] || target < A[(i + 1) % n])
            return false;
        
        if (target >= A[0]) {
            lo = 0;
            hi = i;
        } else {
            lo = i + 1;
            hi = n - 1;
        }
        
        mid = (lo + hi) / 2;
        while (lo < hi) {
            if (A[mid] == target)
                return true;
            
            if (A[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
            mid = (lo + hi) / 2;
        }
        
        if (A[mid] == target)
            return true;
        return false;        
    }
};
