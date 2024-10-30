// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        const int init_x = x;
        long result = 0;
        if (x < 0) {
            return false;
        }
        while (x > 0) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if (init_x == result) {
            return true;
        }
        return false;
    }
};
