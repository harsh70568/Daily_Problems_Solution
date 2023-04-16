class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        
        int i = 0;
        int j = 0;
        int max_len = 0;
        
        while(j < s.length())
        {
            mpp[s[j]]++;
            
            if(mpp.size() == j-i+1) // condition for all characters to be distinct
            {
                max_len = max(max_len, j-i+1);
                j++;
            }
            else
            {
                while(mpp.size() < j-i+1)
                {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        
        return max_len;
        
    }
};