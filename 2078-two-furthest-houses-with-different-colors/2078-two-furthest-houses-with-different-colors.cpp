class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i=0;
        int j=n-1;

        while(i<n && colors[i]==colors[n-1]){
            i++;
        }
        while(j>=0 && colors[j]==colors[0]){
            j--;
        }

        return max(j,n-1-i);
        
    }
};