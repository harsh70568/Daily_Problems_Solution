class Solution {
public:
    bool is_palindrome(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
    void solve(int index, string s, vector<vector<string>> &ans, vector<string> &temp)
    {
        if(index == s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = index; i < s.size(); i++)
        {
            if(is_palindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i-index+1));
                solve(i+1, s, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(0, s, ans, temp);
        
        return ans;
    }
};