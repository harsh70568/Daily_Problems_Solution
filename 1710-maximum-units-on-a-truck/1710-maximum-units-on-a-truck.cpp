class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& ans, int truckSize) {
        
        int count = 0;
        
        sort(ans.begin(),ans.end(),cmp);
        
        for(auto it : ans)
        {
            if(truckSize == 0) return count;
            int mini = min(it[0],truckSize);
            truckSize -= mini;
            count += mini*it[1];
        }
        return count;
    }
};