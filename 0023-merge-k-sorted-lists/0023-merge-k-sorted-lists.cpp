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
    ListNode* convert(vector<int> &ans){
        int n=ans.size();
        if(n==0) return NULL;

        ListNode* head=new ListNode(ans[0]);
        ListNode* temp=head;
        for(int i=1;i<n;i++){
            temp->next=new ListNode(ans[i]);
            temp=temp->next;
        }


        return head;
    }



    ListNode* mergeKLists(vector<ListNode*>& list) {
        int n=list.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            ListNode* temp=list[i];


            while(temp != NULL){
                ans.push_back(temp->val);
                temp=temp->next;
            }
        }

        sort(ans.begin(),ans.end());
        return convert(ans);

        
    }
};