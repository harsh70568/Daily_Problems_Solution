class Solution {
public:
    bool static harsh(const pair<int,int> &a, const pair<int,int> &b)
    {
        return ((a.first-a.second) < (b.first-b.second));
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int,int>> ans;
        for(int i = 0; i < capacity.size(); i++)
        {
            ans.push_back({capacity[i],rocks[i]});
        }
        
        sort(ans.begin(), ans.end(), harsh);
        
        int count = 0;
        for(auto it : ans)
        {
            int diff = it.first-it.second;
            
            if(diff == 0) count++;
            
            else if(additionalRocks >= diff)
            {
                count++;
                additionalRocks -= diff;
            }
        }
        return count;
    }
};