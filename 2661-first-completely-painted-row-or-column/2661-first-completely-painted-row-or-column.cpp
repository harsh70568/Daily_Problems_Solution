class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> mpp;
        unordered_map<int, pair<int, int>> mpp2;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mpp[mat[i][j]] = {i, j};
                mpp2[mat[i][j]] = {j, i};
            }
        }
        
        
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        for(int i = 0; i < arr.size(); i++)
        {
            int r = mpp[arr[i]].first;
            row[r]++;
            
            int r1 = mpp2[arr[i]].first;
            col[r1]++;
            
            if(row[r] == n || col[r1] == m) return i;
        }
        
        return -1;
        
    }
};