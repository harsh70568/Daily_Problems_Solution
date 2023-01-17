class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int ones = 0;
        int zero = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(ones >= 1)
                {
                    zero++;
                }
            }
            else
            {
                ones++;
            }
            if(ones < zero)
            {
                zero = ones;
            }
        }
        
        return zero;
    }
};