class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        sort(piles.begin(),piles.end(), greater<int>());
        int a = 0;
        int b = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            if(i % 2 == 0) a += piles[i];
            else b += piles[i];
        }
        
        return a > b;
    }
};