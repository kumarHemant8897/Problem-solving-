class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        int n=nums1.size();
        int m=nums2.size();
       // vector<int> ans;

        for(int i=m-1 ;i>=0 ;i--){

            int cur=nums2[i];

            while(!st.empty()  && st.top() <= cur){
                st.pop();
            }

            if(st.empty()){
               mp[cur]=-1;

            }
            else{
                mp[cur]=st.top();
            }

            st.push(cur);
        }

        vector<int> ans;
        for(auto it: nums1){
            ans.push_back(mp[it]);
        }
        return ans;


        
    }
};