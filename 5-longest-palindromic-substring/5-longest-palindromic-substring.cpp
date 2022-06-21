class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int lon_l = 1;
        int start = 0;
        if(n == 1) return s;
        for(int i = 1; i < n; i++)
        {
            // check for odd length
            int left = i-1;
            int right = i+1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                
                if(right-left+1 > lon_l)
                {
                    lon_l = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
            //check for even length
            left = i-1;
            right = i;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right-left+1 > lon_l)
                {
                    lon_l = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        
        return s.substr(start,lon_l);
    }
};