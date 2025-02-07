// https://leetcode.com/problems/next-greater-element-i/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&& nums1, vector<int>&& nums2) {
        stack<int> s;
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> nextGreater;

        for (auto num : nums2) {
            while (!s.empty() && num > s.top()) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.find(nums1[i]) != nextGreater.end()) {
                res[i] = nextGreater[nums1[i]];
            }
        }

        return res;
    }
};

int main() {
    Solution o;

    auto res = o.nextGreaterElement(vector<int>{4,1,2}, vector<int>{1,3,4,2});
    // auto res = o.nextGreaterElement(vector<int>{2, 4}, vector<int>{1,2,3,4});

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
