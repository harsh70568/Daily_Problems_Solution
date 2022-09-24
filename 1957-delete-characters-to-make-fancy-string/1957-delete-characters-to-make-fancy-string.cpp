class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1;
        
        for(int i = 0; i < s.length()-1; i++)
        {
            if(s[i] == s[i+1])
            {
                count++;
                if(count < 3)
                {
                    ans += s[i];
                }
            }
            else
            {
                count = 1;
                ans += s[i];
            }  
        }
        ans += s[s.length()-1];
        
        return ans;
    }
};