class Solution {
public:
    double average(vector<int>& salary) {
        double n=salary.size();
        double avg=0;
        double sum=0;
        sort(salary.begin() , salary.end());
        for (int i = 1; i < n-1 ; i++){
             sum= sum + salary[i];
            avg=sum/(n-2);

        }
        return avg;
        
    }
};