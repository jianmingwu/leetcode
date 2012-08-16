class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hi, lo, mid;
        
        lo = 0;
        hi = min(x, 46340);
        mid = (lo + hi) / 2;
        
        while (lo < mid) {
            int t = mid * mid;
            if (t == x)
                return mid;
            
            if (t > x)
                hi = mid;
            else
                lo = mid;
            
            mid = (hi + lo) / 2;
        }
        if (hi * hi <= x)
            return hi;
        else
            return lo;
    }
};
