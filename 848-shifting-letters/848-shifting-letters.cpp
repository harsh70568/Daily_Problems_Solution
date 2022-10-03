class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        long long sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += shifts[i];
        }
        
        long long increase = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                increase = sum;
            }
            else
            {
                increase -= shifts[i-1];
            }
            
            int idx = (s[i] - 'a' + increase) % 26;
            s[i] = 'a' + idx;
        }
        
        return s;
    }
};