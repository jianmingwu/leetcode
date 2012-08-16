#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void genP(vector<string> &vs, string s, int n, int nl, int nr) {
        if (nr == n && nl == n) {
            vs.push_back(s);
            return;
        }

        if (nl < n) {
            string ss(s);
            ss.push_back('(');
            genP(vs, ss, n, nl + 1, nr);
        }

        if (nr < nl) {
            string ss(s);
            ss.push_back(')');
            genP(vs, ss, n, nl, nr + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        string s("(");

        genP(vs, s, n, 1, 0);

        return vs;
    }
};

int main()
{
    Solution s;
    vector<string> vs;

    vs = s.generateParenthesis(3);
    for (int i = 0; i < vs.size(); ++i)
        cout << vs[i] << endl;

    return 0;
}
