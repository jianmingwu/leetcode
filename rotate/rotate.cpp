class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = matrix.size();
        int i, j, n;
        n = len / 2;
        for (i = 0; i < n; ++i) {
            for (j = i; j < len - 1 - i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[len - j - 1][i];
                matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
                matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
                matrix[j][len - i - 1] = t;
            }
        }
        
        return;
    }
};
