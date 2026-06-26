/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Anchors the result list
        ListNode* tail = &dummy;
        int carry = 0;

        // Loop as long as there's a digit to process or a carry left over
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Extract values; if a list is finished, treat its digit as 0
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate sum and update the carry
            int currentSum = val1 + val2 + carry;
            carry = currentSum / 10;
            int digit = currentSum % 10;

            // Create a new node with the single digit and link it
            tail->next = new ListNode(digit);
            tail = tail->next;

            // Shift input pointers forward if they haven't hit the end
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy.next;
    }
};