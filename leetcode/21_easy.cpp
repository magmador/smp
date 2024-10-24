// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge_lists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }

    if (list2 == nullptr) {
        return list1;
    }

    ListNode *node_head = nullptr;
    ListNode *node_tail = nullptr;

    if (list1->val < list2->val) {
        node_head = list1;
        node_tail = merge_lists(list1->next, list2);
    }
    else {
        node_head = list2;
        node_tail = merge_lists(list1, list2->next);
    }
    node_head->next = node_tail;
    return node_head;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge_lists(list1, list2);
    }
};
