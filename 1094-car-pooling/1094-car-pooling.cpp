class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ans(1002,0);
        for(int i = 0; i < trips.size(); i++)
        {
            ans[trips[i][1]] += trips[i][0];
            ans[trips[i][2]] -= trips[i][0];
        }
        if(ans[0] > capacity) return false;
        for(int i = 1; i < 1002; i++)
        {
            ans[i] = ans[i] + ans[i-1];
            if(ans[i] > capacity) return false;
        }
        
        return true;
        
        
    }
};