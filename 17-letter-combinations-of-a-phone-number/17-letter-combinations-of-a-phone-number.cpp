class Solution {
public:
    void solve(string digits, vector<string> &ans, string temp, string mapping[], int index)
    {
        if(index >= digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        int number = digits[index]-'0';
        string value = mapping[number];
        
        for(int i = 0; i < value.length(); i++)
        {
            temp.push_back(value[i]);
            solve(digits,ans,temp,mapping,index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string temp = "";
        int index = 0;
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,temp,mapping,index);
        return ans;
    }
};