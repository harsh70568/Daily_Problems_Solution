class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> ans(p.size());
        for(int i = 0; i < p.size(); i++)
        {
            int j;
            for(j = i+1; j < p.size(); j++)
            {
                if(p[j] <= p[i])
                {
                    break;
                }
            }
            if(j == p.size()) ans[i] = p[i];
            else ans[i] = p[i] - p[j];
        }
        
        return ans;
    }
};