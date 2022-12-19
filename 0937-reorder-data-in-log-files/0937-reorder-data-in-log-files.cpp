class Solution {
public:
    bool static cmp(string &a, string &b)
    {
        auto str1 = string(a.begin() + a.find(' '), a.end());
        auto str2 = string(b.begin() + b.find(' '), b.end());
        
        return (str1 == str2) ? a < b : str1 < str2;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<string> letter_logs;
        vector<string> digit_logs;
        
        for(int i = 0; i < logs.size(); i++)
        {
            if(logs[i][logs[i].length()-1] >= 48 && logs[i][logs[i].length()-1] <= 57)
            {
                digit_logs.push_back(logs[i]);
            }
            else
            {
                letter_logs.push_back(logs[i]);
            }
        }
        
        sort(letter_logs.begin(), letter_logs.end(), cmp);
        
        for(int i = 0; i < letter_logs.size(); i++)
        {
            ans.push_back(letter_logs[i]);
        }
        
        for(int i = 0; i < digit_logs.size(); i++)
        {
            ans.push_back(digit_logs[i]);
        }
        
        return ans;
        
        
        
        
    }
};