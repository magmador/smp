// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <unordered_map>

class Solution {
public:
    int climbStairs(int n) {
        std::unordered_map<int, int> seq;

        return climbStairs(n, seq);
    }

private:
    int climbStairs(int n, std::unordered_map<int, int>& seq) {
        if (n == 0 || n == 1) {
            return 1;
        }

        if (seq.find(n) == seq.end()) {
            seq[n] = climbStairs(n - 1, seq) + climbStairs(n - 2, seq);
        }
        return seq[n];
    }
};

int main() {
    Solution o;

    std::cout << o.climbStairs(45) << std::endl;

    return 0;
}
