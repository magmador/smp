// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int overall_count = 1;
        size_t new_position = 1;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                continue;
            }
            else {
                nums[new_position++] = nums[i + 1];
                overall_count++;
            }
        }
        return overall_count;
    }
};
