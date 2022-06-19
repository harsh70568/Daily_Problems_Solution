class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> freq(26,-1);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a'] = i;
        }
        
        int start = 0;
        int end = -1;
        int i = 0;
        while(i < s.length())
        {
            end = max(end,freq[s[i]-'a']);
            if(i == end)
            {
                ans.push_back(end-start+1);
                start = i+1;
            }
            
            i++;
        }
        return ans;
        
    }
};