class Solution {
public:
    int minDeletions(string s) {
        int count = 0;
        vector<int> ans;
        
        unordered_map<char,int> mpp;
        set<int> st;
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        
        for(auto it : mpp)
        {
            ans.push_back(it.second);
        }
        
        sort(ans.begin(),ans.end());
        
        for(int i = 0; i < ans.size()-1; i++)
        {
            if(ans[i] == ans[i+1])
            {
                count++;
                int curr_elem = ans[i];
                while(st.find(curr_elem-1) != st.end())
                {
                    count++;
                    curr_elem = curr_elem - 1;
                }
                if(curr_elem-1 != 0) st.insert(curr_elem-1);
            }
            st.insert(ans[i]);
        }
        
        return count;
    }
};