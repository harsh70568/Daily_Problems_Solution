class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int max_length = 1;
        for(int i = 1; i < n; i++)
        {
            int left = i-1;
            int right = i;
            
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(max_length < right-left+1)
                {
                    max_length = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
            
            left = i-1;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(max_length < right-left+1)
                {
                    max_length = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        
        return s.substr(start,max_length);
    }
};