class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        
        int j = 0;
        int count = 0;
        string temp = "";
        
        for(int i = 0; i < s.length(); i++)
        {
            if(j < spaces.size() && count == spaces[j])
            {
                ans += temp;
                ans.push_back(' ');
                temp = s[i];
                j++;
            }
            else
            {
                temp.push_back(s[i]);
            }
            count++;
        }
        ans += temp;
        
        return ans;
    }
};