class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(int i = 0; i < p.length(); i++) freq2[p[i] - 'a']++;
        
        int i = 0;
        int j = 0;
        int k = p.length();
        vector<int> ans;
        while(j < s.length())
        {
            if(p.find(s[j]) != string::npos)
            {
                freq1[s[j] - 'a']++; // contribution added
            }
            
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)   // window of size k
            {
                if(freq1 == freq2) ans.push_back(i);
                if(p.find(s[i]) != string::npos) freq1[s[i] - 'a']--;   // contribution withdrawal
                
                // slide window
                i++;
                j++;
            }
        }
        
        return ans;
    }
};