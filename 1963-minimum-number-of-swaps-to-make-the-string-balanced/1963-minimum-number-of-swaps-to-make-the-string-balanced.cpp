class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        if(st.size() == 0) return 0;
        if(st.size() == 2) return 1;
        else
        {
            if(st.size() % 4 == 0) return st.size()/4;
            else return st.size()/4+1;
        }
    }
};