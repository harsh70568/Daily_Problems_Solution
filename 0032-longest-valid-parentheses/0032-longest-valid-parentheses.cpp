class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                if(st.empty()) s[i] = '#';
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
        
        //cout<<s<<endl;
        
        int maxi = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '#')
            {
                maxi = max(maxi, cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};