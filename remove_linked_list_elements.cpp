/*

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* first = nullptr;
        ListNode* second = head;
        
        while(second) {
            if (second->val == val) {
                ListNode* temp = second;
                if (first) {
                    first->next = second->next;
                } else {
                    head = second->next;
                }
                second = second->next;
                delete(temp);
                temp = nullptr;
            } else {
                first = second;
                second = second->next;
            }
        }
        return head;
    }
};