// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> romanVal = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (auto i = s.end() - 1; i >= s.begin(); i--) {
            int current_value = romanVal[*i];

            if (i != s.end() - 1) {
                int prev_value = romanVal[*(i + 1)];
                if (current_value < prev_value) {
                    result -= current_value;
                }
                else {
                    result += current_value;
                }
            }
            else {
                result += current_value;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    string s = "LVIII";
    int result = obj.romanToInt(s);
    cout << result << endl;
    return 0;
}
