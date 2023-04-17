class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        
        int max_len = 1;
        int start = 0;
        
        int left = -1;
        int right = -1;
        for(int i = 1; i < n; i++)
        {
            // check for odd length
            left = i-1;
            right = i+1;
            
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right - left + 1 > max_len)
                {
                    max_len = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
            
            // check for even length
            left = i-1;
            right = i;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right - left + 1 > max_len)
                {
                    max_len = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        
        return s.substr(start, max_len);
        
    }
};