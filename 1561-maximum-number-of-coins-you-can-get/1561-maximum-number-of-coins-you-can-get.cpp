class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        n /= 3;
        sort(piles.begin(), piles.end(), greater<int>());
        
        int i = 1;
        int me = 0;
        while(n--)
        {
            me += piles[i];
            i += 2;
        }
        return me;
        
    }
};