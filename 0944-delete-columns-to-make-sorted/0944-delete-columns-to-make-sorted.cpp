class Solution {
public:
    bool is_not_sorted(vector<char> &st)
    {
        for(int i = 1; i < st.size(); i++)
        {
            if(st[i] < st[i-1]) return true;
        }
        
        return false;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int cnt = 0;
        int len = strs[0].length();
        for(int i = 0; i < len; i++)
        {
            vector<char> st;
            for(int j = 0; j < n; j++)
            {
                st.push_back(strs[j][i]);
            }
            if(is_not_sorted(st) == true) cnt++;
        }
        
        return cnt;
        
    }
};