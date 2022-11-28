class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        
        
        unordered_map<int, int> mpp;
        for(int i = 0; i < matches.size(); i++)
        {
            mpp[matches[i][1]]++;
        }
        
        vector<int> winner;
        vector<int> loss;
        set<int> s;
        set<int> s2;
        for(int i = 0; i < matches.size(); i++)
        {
            if(mpp.find(matches[i][0]) == mpp.end() && s.find(matches[i][0]) == s.end())
            {
                winner.push_back(matches[i][0]);
                s.insert(matches[i][0]);
            }
            if(mpp[matches[i][1]] == 1 && s2.find(matches[i][1]) == s2.end())
            {
                loss.push_back(matches[i][1]);
                s2.insert(matches[i][1]);
            }
        }
        
        
        sort(winner.begin(), winner.end());
        sort(loss.begin(), loss.end());
        
        
        ans.push_back(winner);
        ans.push_back(loss);
        
        return ans;
    }
};