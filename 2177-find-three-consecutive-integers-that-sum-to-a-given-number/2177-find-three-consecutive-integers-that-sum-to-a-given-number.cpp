class Solution {
public:
    vector<long long> sumOfThree(long long num) {

        if(num%3 != 0){
            return {};
        }


       long long first=(num/3)-1;
       long long second=first+1;
       long long third=first+2;
       
       return {first,second,third};

        
    }
};