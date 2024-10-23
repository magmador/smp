// https://leetcode.com/problems/merge-sorted-array/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) { nums1 = nums2; return; }
        int last = m + n - 1;

        while (n > 0 && m > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[last] = nums1[m - 1];
                m--;
            }
            else {
                nums1[last] = nums2[n - 1];
                n--;
            }
            last--;
        }

        while (n > 0) {
            nums1[last] = nums2[n - 1];
            last--;
            n--;
        }
    }
};

int main() {
    Solution o;
    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};
    int m = 3;
    int n = 3;

    o.merge(v1, m, v2, n);

    return 0;
}
