class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(int i = 0; i < s1.length(); i++)
        {
            freq[s1[i]-'a']++;
        }
        
        int i = 0;
        int j = 0;
        int total_char = s1.length();
        while(j < s2.length())
        {
            if(freq[s2.at(j++)-'a']-- > 0)
            {
                total_char--;
            }
            if(total_char == 0) return true;
            if(j-i == s1.size() && freq[s2.at(i++)-'a']++ >= 0)
            {
                total_char++;
            }
        }
        return false;
    }
};