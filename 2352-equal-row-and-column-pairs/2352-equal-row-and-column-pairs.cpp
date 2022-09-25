class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        
        map<vector<int>, int> mpp;
        
        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
            {
                temp.push_back(grid[j][i]);
            }
            
            mpp[temp]++;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(mpp.find(grid[i]) != mpp.end()) count += mpp[grid[i]];
        }
        
        return count;
        
        
    }
};