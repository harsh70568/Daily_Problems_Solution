class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(),spaces.end());
        string ans = "";
        
        int j = 0;
        int count = 1;
        string temp = "";
        temp += s[0];
        if(spaces[0] == 0)
        {
            ans += " ";
            j++;
        }
        for(int i = 1; i < s.length(); i++)
        {
            if(j < spaces.size() && count == spaces[j])
            {
                ans += temp;
                ans += " ";
                temp = s[i];
                j++;
                
            }
            else
            {
                temp += s[i];
                //count++;
            }
            count++;
        }
        ans += temp;
        
        return ans;
    }
};