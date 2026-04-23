class Solution {
public:
   
   static bool cmp(vector<int> &a, vector<int> &b){
       return a[1] > b[1];
   }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int totunits = 0;

        for(int i = 0; i < n; i++){
            int boxes = boxTypes[i][0];   
            int units = boxTypes[i][1];

            int take = min(boxes, truckSize);
            totunits += take * units;    
            truckSize -= take;

            if(truckSize == 0) break;    
        }

        return totunits;
    }
};