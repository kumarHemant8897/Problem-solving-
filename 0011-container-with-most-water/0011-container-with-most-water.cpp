class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int rh=n-1;
        int lh=0;
        int maxarea=INT_MIN;

        while( lh < rh ){
            int wid=rh-lh;
            int hg=min(height[lh],height[rh]);
            int area=wid*hg;

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