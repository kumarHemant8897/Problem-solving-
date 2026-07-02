class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int st=capacity;
        int steps=0;

        for(int i=0;i<n;i++){
            if(st < plants[i]){
                steps += 2 * i;
                st=capacity;
            }
            steps++;
            st-=plants[i];
        }

        return steps;
    }
};