#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cnt = 0;
        bool sp;
        const char *p = s;

        sp = true;
        while (*p != '\0') {
            if (*p == ' ')
                sp = true;
            else {
                if (sp == true) {
                    sp = false;
                    cnt = 1;
                } else
                    ++cnt;
            }
            ++p;
        }

        return cnt;
    }
};

int main()
{
    char a[] = "Hello World";
    Solution s;

    cout << s.lengthOfLastWord(a) << endl;
    return 0;
}
