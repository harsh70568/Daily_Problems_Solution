class Solution {
public:
    bool is_possible(string &s, string &p, vector<int> &rem, int mid)
    {
        unordered_set<int> st;
        int n = rem.size();
        for(int i = 0; i < min(mid, n); i++)
        {
            st.insert(rem[i]);
        }
        
        int i = 0;
        int j = 0;
        while(i < s.length() && j < p.length())
        {
            if(st.find(i) != st.end())
            {
                i++;
            }
            else
            {
                if(s[i] == p[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        
        return j == p.length();
    }
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int low = 1;
        int high = rem.size();
        int ans = 0;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(s, p, rem, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};