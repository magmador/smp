// https://leetcode.com/problems/two-sum/description/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> visited;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto found_value = visited.find(complement);

            // Found
            if (found_value != visited.end()) {
                return {visited[complement], i};
            }

            visited[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector <int> vec = {-3,4,3,90};
}
