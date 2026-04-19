class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i=0;
        int j=n-1;
        int maxdis=0;

        while(j>0){
            if(colors[j] != colors[0]){
                maxdis=j;
                break;
            }
            j--;
        }

        while(i<n){
            if(colors[i] != colors[n-1]){
                maxdis=max(maxdis,n-1-i);
                break;
            }
            i++;
        }

        return maxdis;

      

        
        
    }
};