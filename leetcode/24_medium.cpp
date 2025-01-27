// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int tmp = 0;
        ListNode *node = head;
        while (node != nullptr) {
            if (node->next == nullptr) {
                break;
            }
            tmp = node->next->val;
            node->next->val = node->val;
            node->val = tmp;

            node = node->next;
            node = node->next;
        }
        return head;
    }
};
