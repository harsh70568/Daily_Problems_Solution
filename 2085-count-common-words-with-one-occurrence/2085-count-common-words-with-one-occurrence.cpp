class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mpp1;
        unordered_map<string, int> mpp2;
        
        for(auto it : words1)
        {
            mpp1[it]++;
        }
        
        for(auto it : words2)
        {
            mpp2[it]++;
        }
        int count = 0;
        for(int i = 0; i < words2.size(); i++)
        {
            if(mpp1[words2[i]] == 1 && mpp2[words2[i]] == 1)
            {
                count++;
            }
        }
        
        return count;
    }
};