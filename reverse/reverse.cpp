class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int px;
        
        if (x < 0)
            px = -x;
        else
            px = x;
        
        while (px) {
            int t = px % 10;
            px /= 10;
            ret = ret * 10 + t;
        }
        
        if (x < 0)
            ret = -ret;
        
        return ret;
    }
};
