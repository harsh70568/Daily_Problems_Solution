class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            unordered_map<char, int> mpp;
            for(int j = i; j < s.length(); j++)
            {
                mpp[s[j]]++;
                
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto it : mpp)
                {
                    if(it.second > maxi) maxi = it.second;
                    if(it.second < mini) mini = it.second;
                }
                
                ans += (maxi - mini);
            }
        }
        
        return ans;
    }
};