// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution o;

    std::cout << o.minCostClimbingStairs(cost) << std::endl;

    return 0;
}
