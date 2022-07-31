class Solution {
public:
    void solve(string digits,vector<string> &ans, int index, string mapping[],string temp)
    {
        if(index >= digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        int value = digits[index]-'0';
        string str = mapping[value];
        for(int i = 0; i < str.length(); i++)
        {
            temp.push_back(str[i]);
            solve(digits,ans,index+1,mapping,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        int i = 0;
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string str = "";
        solve(digits,ans,i,mapping,str);
        return ans;
    }
};