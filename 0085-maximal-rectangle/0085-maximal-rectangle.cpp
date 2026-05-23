class Solution {
public:

    vector<int> nse(vector<int> &arr){
        
        int n = arr.size();
        stack<int> st;
        vector<int> next(n);

        for(int i = n - 1; i >= 0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                next[i] = n;
            }
            else{
                next[i] = st.top();
            }

            st.push(i);
        }

        return next;
    }

    
    vector<int> pse(vector<int> &arr){
        
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n);

        for(int i = 0; i < n; i++){
            
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()){
                prev[i] = -1;
            }
            else{
                prev[i] = st.top();
            }

            st.push(i);
        }

        return prev;
    }


    int largestHist(vector<int> &arr){
        
        int n = arr.size();
        int maxi = 0;

        vector<int> prev = pse(arr);
        vector<int> next = nse(arr);

        for(int i = 0; i < n; i++){
            
            int width = next[i] - prev[i] - 1;
            int area = arr[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }



    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        int maxarea = 0;

        vector<vector<int>> presum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            
            int sum = 0;

            for(int i = 0; i < n; i++){

                if(mat[i][j] == '0'){
                    sum = 0;
                }
                else{
                    sum += 1;
                }

                presum[i][j] = sum;
            }
        }

        for(int i = 0; i < n; i++){
            
            int area = largestHist(presum[i]);

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};