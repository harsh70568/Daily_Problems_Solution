class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        
        for(int i = 0; i < p.length(); i++)
        {
            freq2[p[i] - 'a']++;
        }
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        int k = p.length();
        while(j < s.length())
        {
            if(p.find(s[j]) != std::string::npos)
            {
                freq1[s[j] - 'a']++;
            }
            
            if(j-i+1 < k) j++;
            else if(j-i+1 == k)
            {
                if(freq1 == freq2) ans.push_back(i);
                if(p.find(s[i]) != std::string::npos) freq1[s[i] - 'a']--;
                i++;
                j++;
            }
            
        }
        
        return ans;
    }
    
};