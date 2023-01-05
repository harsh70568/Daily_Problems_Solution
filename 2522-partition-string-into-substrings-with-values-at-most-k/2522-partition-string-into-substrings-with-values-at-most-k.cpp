class Solution {
public:
    int minimumPartition(string s, int k) {
        for(int i = 0; i < s.length(); i++)
        {
            int val = s[i] - '0';
            if(val > k) return -1;
        }
        
        long long val = s[0] - '0';
        int ans = 1;
        for(int i = 0; i < s.length()-1; i++)
        {
            val = val*10 + (s[i+1] - '0');
            if(val > k)
            {
                ans++;
                val = (s[i+1] - '0');
            }
        }
        
        return ans;
        
        
    }
};