class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        if(s[0] == '1') prefix[0] = 1;
        else prefix[0] = 0;
        
        if(s[n-1] == '0') suffix[n-1] = 1;
        else suffix[n-1] = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '1') prefix[i] = prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            if(s[i] == '0') suffix[i] = suffix[i+1] + 1;
            else suffix[i] = suffix[i+1];
        }
        
        //for(auto it : prefix) cout<<it<<" ";
        //for(auto it : suffix) cout<<it<<" ";
        
        int mini = 1e9;
        for(int i = 1; i < n-1; i++)
        {
            int val = prefix[i-1] + suffix[i+1];
            mini = min(mini, val);
        }
        
        mini = min(mini, suffix[1]);
        mini = min(mini, prefix[n-2]);
        
        return mini;
    }
};