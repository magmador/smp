// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int i = 0;
        string result = "";
        char curr_char;

        while(true)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                if (i >= strs[j].length()) return result;

                if (j == 0) {
                    curr_char = strs[j][i];
                }

                if (strs[j][i] != curr_char)
                {
                    return result;
                }
            }
            result += curr_char;
            i++;
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<string> strs = {"flower", "flower", "flower", "flower"};

    cout << obj.longestCommonPrefix(strs) << endl;
    return 0;
}
