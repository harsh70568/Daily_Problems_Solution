class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> ans(n+1,0);
        
        for(int i = 0; i < shifts.size(); i++)
        {
            int direction = shifts[i][2];
            if(direction == 0)
            {
                ans[shifts[i][0]] -= 1;
                ans[shifts[i][1] + 1] += 1;
            }
            else
            {
                ans[shifts[i][0]] += 1;
                ans[shifts[i][1] + 1] -= 1;
            }
        }
        
        for(int i = 1; i < n+1; i++)
        {
            ans[i] = ans[i] + ans[i-1];
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            int idx = (s[i]-'a' + ans[i]) % 26;
            if(idx < 0) idx += 26;
            char new_char = (char)(idx + 'a');
            s[i] = new_char;
        }
        
        return s;
    }
};