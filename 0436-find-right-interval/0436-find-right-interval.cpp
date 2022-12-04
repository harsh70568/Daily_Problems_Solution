class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        
        map<int, int> mpp;
        for(int i = 0; i < intervals.size(); i++)
        {
            mpp[intervals[i][0]] = i;
        }
        
        for(int i = 0; i < intervals.size(); i++)
        {
            auto it = mpp.lower_bound(intervals[i][1]);
            if(it != mpp.end())
            {
                ans.push_back((*it).second);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};