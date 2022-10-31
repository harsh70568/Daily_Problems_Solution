class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        
        int count = 0;
        int sum = 0;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(flag)
            {
                sum += piles[i];
                i++;
            }
            else
            {
                count++;
                if(count == n/3) flag = true;
            }
        }
        
        return sum;
    }
};