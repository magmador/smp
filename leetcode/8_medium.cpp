// https://leetcode.com/problems/string-to-integer-atoi/

#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool digit_started = false;
        int sign = 0;
        long result = 0;
        int count = 0;

        for (size_t i = 0; i < s.length(); i++) {
            if (!digit_started && s[i] == ' ') continue;
            if (!digit_started && (s[i] == '-' || s[i] == '+')) {
                if (s[i] == '-') {
                    sign = 1;
                }
                if (!isdigit(s[i+1]) || (s[i+1] == ' ')) break;
                continue;
            }
            if (!isdigit(s[i])) break;
            if (count > 11) break;

            int ch = s[i] - '0';
            result *= 10;
            result += ch % 10;
            ch /= 10;
            digit_started = true;
            if (result) count++;
        }

        if (sign == 1) result *= -1;
        return  (result > INT_MAX ? INT_MAX : (result < INT_MIN ? INT_MIN : result));
    }
};
