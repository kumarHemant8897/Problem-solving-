class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();

        int ans=0;

        for(int i=0;i<n;i++){
            bool found=false;

            for(int j=0;j<m;j++){
                if(baskets[j] >= fruits[i]){
                    found=true;

                    baskets[j]=-1;
                    break;
                }
            }
            if(found==false){
                ans++;
            }
        }


        return ans;
    }
};