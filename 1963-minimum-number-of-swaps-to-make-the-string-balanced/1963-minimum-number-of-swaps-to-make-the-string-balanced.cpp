class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '[') st.push(s[i]);
            else
            {
                if(st.empty()) continue;
                else st.pop();
            }
        }
        
        if(st.size() <= 1) return st.size();
        else
        {
            if(st.size() % 2 == 0) return st.size() / 2;
            else return st.size() / 2 + 1;
        }
    }
};