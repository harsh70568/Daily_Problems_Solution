class Solution {
public:
    void solve(int index, string digits, vector<string> &ans, string &temp, vector<string> &arr)
    {
        if(index >= digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        string str = arr[digits[index] - '0'];
        for(int i = 0; i < str.length(); i++){
            temp.push_back(str[i]);
            solve(index+1, digits, ans, temp, arr);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
        if(digits.length() == 0) return ans;
        vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp = "";
        
        solve(0, digits, ans, temp, arr);
        
        return ans;
    }
};