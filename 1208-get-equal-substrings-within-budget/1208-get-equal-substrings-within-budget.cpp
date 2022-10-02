class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        int p = 0;
        int k = 0;
        
        int sum = 0;
        int max_len = 0;
        while(j < s.length())
        {
            sum += abs(s[j] - t[k]);
            if(sum <= maxCost)
            {
                max_len = max(max_len,j-i+1);
                j++;
                k++;
            }
            else
            {
                while(sum > maxCost)
                {
                    sum -= abs(s[i] - t[p]);
                    p++;
                    i++;
                }
                j++;
                k++;
            }
        }
        
        return max_len;
    }
};