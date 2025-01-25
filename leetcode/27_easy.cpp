#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t i = 0;
        size_t j = 0;

        for (; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    Solution o;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> expected = {0, 1, 3, 0, 4};

    int expectedSize = o.removeElement(nums, 2);

    for (int i = 0; i < expectedSize; i++) {
        assert(nums[i] == expected[i]);
    }

    return 0;
}
