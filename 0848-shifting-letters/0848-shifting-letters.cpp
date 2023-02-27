class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        
        vector<long long> prefix(n);
        prefix[0] = shifts[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + shifts[i];
        long long sum = accumulate(shifts.begin(), shifts.end(), 0LL);
        
        
        long long j = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                s[i] = (char)((((s[i] + sum) - 'a') % 26) + 'a');
            }
            else
            {
                s[i] = (char)((((s[i] + sum - prefix[j]) - 'a') % 26) + 'a');
                j++;
            }
        }
        
        return s;
        
        
        
    }
};