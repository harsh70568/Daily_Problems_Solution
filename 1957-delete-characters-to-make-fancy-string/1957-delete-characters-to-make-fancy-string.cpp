class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        stack<char> st;
        
        int count = 1;
        for(int i = 0; i < s.length(); i++)
        {
            if(!st.empty() && st.top() == s[i])
            {
                count++;
                if(count < 3)
                {
                    ans += s[i];
                }
            }
            else
            {
                ans += s[i];
                count = 1;
                st.push(s[i]);
            }
        }
        
        return ans;
    }
};