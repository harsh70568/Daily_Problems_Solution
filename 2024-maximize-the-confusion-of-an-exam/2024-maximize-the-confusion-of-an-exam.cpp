class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        unordered_map<char,int> mpp;
        
        int max_len = -1;
        
        while(j < s.length())
        {
            mpp[s[j]]++;
            
            maxi = max(maxi,mpp[s[j]]);
            
            if(j-i+1 - maxi > k)
            {
                mpp[s[i]]--;
                i++;
            }
            
            max_len = max(max_len,j-i+1);
            
            j++;
        }
        
        return max_len;
    }
};