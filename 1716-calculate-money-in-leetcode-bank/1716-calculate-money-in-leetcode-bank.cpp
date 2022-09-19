class Solution {
public:
    int totalMoney(int n) {
        int count = 1;
        int money = 0;
        int k = 1;
        for(int i = 1; i <= n; i++)
        {
            money += count;
            count++;
            if(i % 7 == 0)
            {
                count = k+1;
                k = k+1;
            }
            
        }
        return money;
    }
};