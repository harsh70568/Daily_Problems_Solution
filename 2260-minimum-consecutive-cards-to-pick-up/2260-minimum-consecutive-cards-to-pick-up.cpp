class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i = 0;
        int j = 0;
        
        map<int, int> mpp;
        int min_len = 1e9;
        while(j < cards.size())
        {
            mpp[cards[j]]++;
            
            if(mpp.size() == j-i+1)
            {
                j++;
            }
            else
            {
                while(mpp.size() < j-i+1)
                {
                    min_len = min(min_len, j-i+1);
                    mpp[cards[i]]--;
                    if(mpp[cards[i]] == 0) mpp.erase(cards[i]);
                    i++;
                }
                j++;
            }
        }
        
        return min_len == 1e9 ? -1 : min_len;
    }
};