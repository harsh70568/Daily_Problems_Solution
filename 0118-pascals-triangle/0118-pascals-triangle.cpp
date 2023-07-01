class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> arr(n);
        
        for(int i = 0; i < n; i++)
        {
            arr[i].resize(i+1);
            arr[i][0] = arr[i][arr[i].size()-1] = 1;
            
            for(int j = 1; j < arr[i].size()-1; j++)
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
            
        }
        
        return arr;
    }
};