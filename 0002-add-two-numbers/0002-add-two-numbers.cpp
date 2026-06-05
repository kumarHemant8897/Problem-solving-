class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (temp1 || temp2 || carry) {
            int sum = carry;

            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;

            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        return dummy->next;
    }
};