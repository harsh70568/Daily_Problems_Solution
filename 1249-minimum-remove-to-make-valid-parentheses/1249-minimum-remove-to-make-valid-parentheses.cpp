class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
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
            s[st.top()] = '#';
            st.pop();
        }
        string str = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '#')
            {
                str += s[i];
            }
        }
        return str;
    }
    
};