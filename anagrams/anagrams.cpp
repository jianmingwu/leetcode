#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool str_comp_size(string a, string b) {
    return a.size() < b.size();
}

class Solution {
private:
    struct tag {
        bool head;
        vector<char> hm;
        int next;
        tag() : head(true), hm(26), next(-1) {}
    };

    void create_tag(string s, tag &t) {
        for (int i = 0; i < s.size(); ++i)
            t.hm[s[i] - 'a']++;
    }

    int comp_tag(tag &a, tag &b) {
        for (int i = 0; i < 26; ++i) {
            if (a.hm[i] != b.hm[i])
                return -1;
        }

        return 0;
    }

public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> vs;
        vector<tag> vt(strs.size());
        int i, j;
        int x, y;

        sort(strs.begin(), strs.end(), str_comp_size);

        x = 0;
        y = 1;

        while (y < strs.size()) {
            while (y < strs.size() && strs[y].size() == strs[x].size())
                ++y;

            for (i = x; i < y; ++i) {
                create_tag(strs[i], vt[i]);
                for (j = i - 1; j >= x; --j) {
                    if (comp_tag(vt[i], vt[j]) == 0) {
                        vt[j].next = i;
                        vt[i].head = false;
                        break;
                    }
                }
            }
            x = y;
            ++y;
        }

        for (i = 0; i < strs.size(); ++i) {
            if (vt[i].head == true && vt[i].next >= 0) {
                vs.push_back(strs[i]);
                j = vt[i].next;
                while (j >= 0) {
                    vs.push_back(strs[j]);
                    j = vt[j].next;
                }
            }
        }

        return vs;
    }
};

int main()
{
    string s1("tea");
    string s2("and");
    string s3("ate");
    string s4("eat");
    string s5("dan");
    vector<string> vs;

    vs.push_back(s1);
    vs.push_back(s2);
    vs.push_back(s3);
    vs.push_back(s4);
    vs.push_back(s5);

    Solution s;
    vector<string> v;
    v = s.anagrams(vs);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    return 0;
}
