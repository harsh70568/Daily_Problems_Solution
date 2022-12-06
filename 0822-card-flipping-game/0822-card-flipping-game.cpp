class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int mini = INT_MAX;
        unordered_map<int, int> mpp;
        for(int i = 0; i < fronts.size(); i++)
        {
            if(backs[i] == fronts[i])
            {
                mpp[backs[i]]++;
            }
        }
        
        for(int i = 0; i < backs.size(); i++)
        {
            if(backs[i] != fronts[i])
            {
                if(mpp.find(backs[i]) == mpp.end())
                {
                    mini = min(mini, backs[i]);
                }
                if(mpp.find(fronts[i]) == mpp.end())
                {
                    mini = min(mini, fronts[i]);
                }
            }
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};