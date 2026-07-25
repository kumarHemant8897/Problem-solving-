class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lh=0;
        int rh=n-1;
        int maxarea=INT_MIN;

        while(lh < rh){
            int wid=rh-lh;
            int ht=min(height[lh] , height[rh]);
            int area=ht * wid;
            maxarea=max(maxarea,area);


            if(height[lh] < height[rh]){
                lh++;
            }
            else{
                rh--;
            }
        }

        return maxarea;
        
    }
};