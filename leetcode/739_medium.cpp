// https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size(), 0);
        unordered_map<int, int> nextGreater;
        int prevDay = 0;

        for (size_t i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                prevDay = s.top();
                res[prevDay] = i - prevDay;
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(temperatures);

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
