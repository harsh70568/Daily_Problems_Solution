class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int count = 0;
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    if(i < s.length()-1 && s[i+1] == ')')
                    {
                        ans += 1;
                        i++;
                    }
                    else
                    {
                        ans += 2;
                    }
                }
                else if(i < s.length()-1 && s[i+1] == ')')
                {
                    st.pop();
                    i++;
                }
                else
                {
                    ans += 1;
                    st.pop();
                }
            }
        }
        ans += st.size()*2;
        
        return ans;
    }
};