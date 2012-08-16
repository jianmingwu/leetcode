class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hi, lo, mid, li, ri;
        vector<int> v;
        
        if (n == 0) {
            li = ri = -1;
            goto out;
        }
            
        lo = 0;
        hi = n - 1;
        mid = (lo + hi) / 2;
        while (lo < hi) {
            if (A[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
            mid = (lo + hi) / 2;
        }
        if (A[mid] == target)
            li = mid;
        else {
            li = ri = -1;
            goto out;
        }
        
        lo = 0;
        hi = n - 1;
        mid = (lo + hi) / 2;
        while (lo < hi) {
            if (A[mid] > target)
                hi = mid - 1;
            else
                lo = mid;
            mid = (lo + hi + 1) / 2;
        }
        ri = mid;
        
out:
        v.push_back(li);
        v.push_back(ri);
        return v;
    
