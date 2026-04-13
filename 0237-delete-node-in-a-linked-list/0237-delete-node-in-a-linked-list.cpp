class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return; // safety (though last node won't be given)
        }

        node->val = node->next->val;     // copy next value
        ListNode* temp = node->next;     // store next node
        node->next = node->next->next;   // skip next node
        delete temp;                     // delete it
    }
};