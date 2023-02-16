class Solution {
public:
    bool is_vowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        int cnt = 0;
        
        while(j < s.length())
        {
            if(is_vowel(s[j]))
            {
                cnt++;
            }
            
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                maxi = max(maxi, cnt);
                if(is_vowel(s[i]))
                {
                    cnt--;
                }
                i++;
                j++;
            }
        }
        
        return maxi;
    }
};