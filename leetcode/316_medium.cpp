// https://leetcode.com/problems/remove-duplicate-letters/

/**
 * Input: s = "bcabc"
 * Output: "abc"
 * Input: s = "cbacdcbc"
 * Output: "acdb"
 */

#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;
        string result;

        for (char& curr_ch : s) {
            freq[curr_ch]++;
        }

        for (auto const& i : freq) {
            std::cout << i.first << " " << i.second << std::endl;
        }
        cout << endl;

        for (char& curr_ch: s) {
            freq[curr_ch]--;


            if (visited[curr_ch] == true) {
                continue;
            }

            // Remove chars if we will see them in future and if current char is lower then the last written one
            while (!result.empty() && curr_ch < result.back() && freq[result.back()] > 0) {
                // Make removed char not visited before removing. We want to add in future
                visited[result.back()] = false;
                result.pop_back();
            }

            // Add unique char in the end of the string
            result.push_back(curr_ch);
            visited[curr_ch] = true;
        }

        return result;
    }
};

int main() {
    Solution o;

    auto s = o.removeDuplicateLetters("cbacdcbc");

    return 0;
}
