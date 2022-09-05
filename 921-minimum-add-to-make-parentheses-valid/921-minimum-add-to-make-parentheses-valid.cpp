class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<int> st;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(st.empty() && s[i] == ')') count++;
            else if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')') st.pop();
        }
        
        return st.size()+count;
    }
};