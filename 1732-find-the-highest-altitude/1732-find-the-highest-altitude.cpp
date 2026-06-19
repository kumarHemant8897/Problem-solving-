class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int maxAltitude=0;
        int altitude=0;

        int netgain=0;
        for(int i=0;i<n;i++){

            altitude += gain[i];
            maxAltitude=max(maxAltitude,altitude);
        }

        return maxAltitude;
        
    }
};