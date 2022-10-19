class Solution {
public:
    bool check(stack<char> st, string s)
    {
        int j = s.length()-1;
        while(j >= 0 && s[j] == st.top() && !st.empty())
        {
            st.pop();
            j--;
        }
        
        return (j == -1);
        
    }
    string removeOccurrences(string s, string part) {
        int n = part.length();
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)
        {
            st.push(s[i]);
            //if(st.size() >= n){
            if(st.size() >= n && check(st, part))
            {
                int size = n;
                while(size--)
                {
                    st.pop();
                }
            }
            //}
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};