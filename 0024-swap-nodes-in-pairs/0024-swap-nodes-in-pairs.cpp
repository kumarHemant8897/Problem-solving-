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
    ListNode* swapPairs(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;

        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        
        for(int i = 0; i + 1 < ans.size() ; i += 2){
            swap(ans[i], ans[i + 1]);
        }

        temp = head;
        int i = 0;

        while(temp != NULL){
            temp->val = ans[i++];
            temp = temp->next;
        }

        return head;
    }
};