class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        unordered_map<int, int> mpp;
        
        for(int i = 0; i < matches.size(); i++)
        {
            mp[matches[i][0]]++;
            mpp[matches[i][1]]++;
            
        }
        vector<int> loss;
        vector<int> win;
        
        for(auto it : mpp)
        {
            if(it.second == 1)
            {
                loss.push_back(it.first);
            }
        }
        
        for(auto it : mp)
        {
            if(mpp.find(it.first) == mpp.end())
            {
                win.push_back(it.first);
            }
        }
        
        sort(win.begin(), win.end());
        sort(loss.begin(), loss.end());
        
        return {win,loss};
        
        
    }
};