class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int, int> mpp;
        
        int count = 0;
        for(int i = 0; i < ans.size(); i++)
        {
            if(mpp[ans[i]] > 0)
            {
                mpp[ans[i]]--;
            }
            else
            {
                count += 1;
                count += ans[i];
                mpp[ans[i]] += ans[i];
            }
        }
        
        return count;
    }
};