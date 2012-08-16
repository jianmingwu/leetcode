#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<vector<int> > vv;
        vector<int> vi;
        int ls, i, j, k, x, y;
        size_t found;

        sort(L.begin(), L.end());
        ls = L[0].size();
        if (ls * L.size() > S.size())
            return vi;

        for (i = 0; i < ls; ++i) {
            vector<int> v((S.size() - i) / ls, -1);
            vv.push_back(v);
        }

        vector<int> pat(L.size(), 0);
        for (k = 0; k < L.size(); ++k) {
            if (k > 0 && L[k - 1].compare(L[k]) == 0) {
                i = k - 1;
                while (pat[i] == 0)
                    --i;
                ++pat[i];
                continue;
            }

            pat[k] = 1;
            i = 0;
            do {
                found = S.find(L[k], i);
                if (found != string::npos) {
                    i = (int)found + 1;
                    x = (int)found % ls;
                    y = (int)found / ls;
                    if (vv[x][y] == -1)
                        vv[x][y] = k;
                } else
                    break;
            } while (true);
        }
        
        for (k = 0; k < ls; ++k) {
            i = 0;
            while (i + L.size() <= vv[k].size()) {
                while (i + L.size() <= vv[k].size() && vv[k][i] == -1)
                    ++i;

                if (i + L.size() <= vv[k].size()) {
                    vector<int> vp(pat);
                    for (j = 0; j < L.size(); ++j) {
                        int t = vv[k][i + j];
                        if (t >= 0 && vp[t] > 0) {
                            vp[t]--;
                        } else
                            break;
                    }
                    if (j == L.size())
                        vi.push_back(i * ls + k);
                }
                ++i;
            }
        }

        return vi;
    }
};

int main()
{
    string S("a");
    string l1("a");
    vector<string> vs;
    Solution s;
    vector<int> vi;

    vs.push_back(l1);

    vi = s.findSubstring(S, vs);
    for (int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;

    return 0;
}
