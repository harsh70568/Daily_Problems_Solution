class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push({s[i],i});
            }
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    s[i] = '#';
                }
                else
                {
                    st.pop();
                }
            }
        }
        
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            s[it.second] = '#';
        }
        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '#')
            {
                str += s[i];
            }
        }
        return str;
    }
};