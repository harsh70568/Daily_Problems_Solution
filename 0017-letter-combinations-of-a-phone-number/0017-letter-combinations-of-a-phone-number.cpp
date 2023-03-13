class Solution {
public:
    void solve(int index, vector<string> &ans, vector<string> &map, string &temp, string digits)
    {
        if(index >= digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        string str = map[digits[index] - '0'];
        for(int i = 0; i < str.size(); i++)
        {
            temp.push_back(str[i]);
            solve(index+1, ans, map, temp, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string> ans;
        if(digits == "") return ans;
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(0, ans, map, temp, digits);
        
        return ans;
    }
};