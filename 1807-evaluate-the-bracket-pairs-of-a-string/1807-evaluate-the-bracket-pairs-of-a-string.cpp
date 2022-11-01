class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        
        for(int i = 0; i < knowledge.size(); i++)
        {
            mpp[knowledge[i][0]] = knowledge[i][1]; 
        }
        
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                string temp = "";
                while(s[i] != ')')
                {
                    temp += s[i+1];
                    i++;
                }
                temp.pop_back();
                
                if(mpp.find(temp) != mpp.end())
                {
                    ans += mpp[temp];
                }
                else
                {
                    ans += '?';
                }
            }
            else
            {
                ans += s[i];
            }
        }
        
        return ans;
    }
};