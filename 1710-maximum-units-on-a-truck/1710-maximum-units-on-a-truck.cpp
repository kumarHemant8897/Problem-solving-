class Solution {
public:

   static bool cmp(vector<int> &a,vector<int> &b){
    return a[1] > b[1];
   }


    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        int totalunits=0;
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        for(int i=0;i<n;i++){
            int box=boxTypes[i][0];
            int units=boxTypes[i][1];

            int take=min(box,truckSize);
            totalunits += take * units;

            truckSize -= take;


            if(truckSize == 0) break;
        }

        return totalunits;
        
    }
};