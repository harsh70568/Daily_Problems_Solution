class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int min_len = INT_MAX;
        
        int i = 0;
        int j = 0;
        
        unordered_map<int,int> mpp;
        while(j < cards.size())
        {
            mpp[cards[j]]++;
            
            if(j-i+1 == mpp.size())
            {
                j++;
            }
            else
            {
                while(mpp.size() != j-i+1)
                {
                    mpp[cards[i]]--;
                    if(mpp[cards[i]] == 0) mpp.erase(cards[i]);
                    i++;
                }
                j++;
                 min_len = min(min_len,j-i+1);
            }
        }
        
        return min_len == INT_MAX ? -1 : min_len;
    }
};