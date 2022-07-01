class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> ans;
        
        int count = 0;
        for(auto it : boxTypes)
        {
            ans.push_back({it[1],it[0]});
        }
        
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        
        for(auto it : ans)
        {
            if(truckSize == 0) return count;
            int mini = min(it.second,truckSize);
            truckSize -= mini;
            count += mini*it.first;
        }
        return count;
    }
};