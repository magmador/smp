// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty() || needle.length() > haystack.length()) {
            return -1;
        }

        auto lps = calculateLPS(needle);
        size_t i = 0;
        size_t j = 0;

        while (i < haystack.length()) {
            if (needle[j] != haystack[i]) {
                if (j == 0) {
                    i++;
                }
                else {
                    j = lps[j - 1];
                }
            }
            else {
                i++;
                j++;
            }

            if (j == needle.length()) {
                return i - j;
            }
        }

        return -1;
    }

private:
    // Longest Prefix Suffix calculation
    vector<int> calculateLPS(const string& needle) {
        vector<int> lps(needle.length(), 0);
        size_t i = 1;
        size_t j = 0;

        while (i < needle.length()) {
            if (needle[i] == needle[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j == 0) {
                    lps[i] = 0;
                    i++;
                }
                else {
                    j = lps[j - 1];
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution o;
    cout << o.strStr("sadbutsad", "sad") << endl;
    return 0;
}
