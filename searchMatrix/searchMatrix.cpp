class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m, n, z, hi, lo, mid;
        
        m = matrix.size();
        n = matrix[0].size();
        z = m * n;
        
        lo = 0;
        hi = z - 1;
        mid = (hi + lo) / 2;
        
        while (lo <= hi) {
            int t = matrix[mid / n][mid % n];
            if (t == target)
                return true;
            
            if (t > target)
                hi = mid - 1;
            else
                lo = mid + 1;
            
            mid = (hi + lo) / 2;
        }
        
        return false;
    }
};
