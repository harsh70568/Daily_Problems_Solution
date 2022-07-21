class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
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
        //cout<<s;
        
        int max_length = 0;
        int curr_length = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '#')
            {
                max_length = max(max_length,curr_length);
                curr_length = 0;
            }
            else
            {
                curr_length++;
            }
        }
        max_length = max(max_length,curr_length);
        return max_length;
    }
};