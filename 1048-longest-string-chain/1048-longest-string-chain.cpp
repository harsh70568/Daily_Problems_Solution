class Solution {
public:
    bool check(string &a, string &b)
    {
        if(b.length() - a.length() != 1) return false;
        
        int i = 0;
        int j = 0;
        while(i < a.length() && j < b.length())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        
        return i == a.length();
    }
    int solve(int index, int prev_idx, vector<string> &words, vector<vector<int>> &dp)
    {
        if(index >= words.size()) return 0;
        
        if(dp[index][prev_idx+1] != -1) return dp[index][prev_idx+1];
        
        int not_pick = 0 + solve(index+1, prev_idx, words, dp);
        int pick = INT_MIN;
        if(prev_idx == -1 || check(words[prev_idx], words[index]))
        {
            pick = 1 + solve(index+1, index, words, dp);
        }
        
        return dp[index][prev_idx+1] = max(pick, not_pick);
    }
    static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        sort(words.begin(), words.end(), cmp);
        
        return solve(0, -1, words, dp);
    }
};