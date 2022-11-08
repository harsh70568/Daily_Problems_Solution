class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(!st.empty() && (s[i] == st.top()-32 || s[i] == st.top()+32))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};