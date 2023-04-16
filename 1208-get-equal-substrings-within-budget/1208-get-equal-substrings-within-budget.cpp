class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int max_len = 0;
        while(j < s.length())
        {
            sum += abs(s[j] - t[j]);
            
            if(sum <= maxCost) // within budget
            {
                max_len = max(max_len, j-i+1);
                j++;
            }
            else
            {
                while(sum > maxCost)
                {
                    sum -= abs(s[i] - t[i]);
                    i++;
                }
                j++;
            }
        }
        
        return max_len;
    }
};