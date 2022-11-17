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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = nullptr;
        ListNode *greater = nullptr;
        ListNode *less_root = nullptr;
        ListNode *greater_root = nullptr;
        while (head != nullptr) {
            if (head->val < x) {
                if (less != nullptr) {
                    less->next = head;
                } else {
                    less_root = head;
                }
                less = head;
            } else {
                if (greater != nullptr) {
                    greater->next = head;
                } else {
                    greater_root = head;
                }
                greater = head;
            }
            head = head->next;
        }

        if (greater != nullptr) {
            greater->next = nullptr;
        }
        if (less_root == nullptr) {
            return greater_root;
        } else {
            if (less != nullptr) {
                less->next = greater_root;
            }
            return less_root;
        }
    }
};
