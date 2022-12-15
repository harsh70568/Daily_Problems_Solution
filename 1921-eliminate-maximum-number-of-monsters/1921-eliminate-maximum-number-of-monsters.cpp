class Solution {
public:
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> ans;
        for(int i = 0; i < dist.size(); i++)
        {
            int val = (dist[i] % speed[i] == 0) ? dist[i] / speed[i] : (dist[i] / speed[i]) + 1;
            ans.push_back(val);
        }
        
        sort(ans.begin(), ans.end());
        
        int monster_you_can_defeat = 1;
        int time_required = 1;
        for(int i = 1; i < ans.size(); i++)
        {
            if(time_required >= ans[i]) return monster_you_can_defeat;
            time_required++;
            monster_you_can_defeat++;
        }
        
        return monster_you_can_defeat;
    }
};