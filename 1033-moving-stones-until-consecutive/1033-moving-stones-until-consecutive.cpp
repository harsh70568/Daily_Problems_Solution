class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int sum = a + b + c;
        int mini = min({a,b,c});
        int maxi = max({a,b,c});
        
        a = mini;
        b = sum - mini - maxi;
        c = maxi;
        
        int maxi_moves = c - a - 1 - 1;
        int mini_moves = 0;
        
        int diff_1 = b - a - 1;
        int diff_2 = c - b - 1;
        if(diff_1 == 0 && diff_2 == 0)
        {
            mini_moves = 0;
        }
        else if(diff_1 <= 1 || diff_2 <= 1)
        {
            mini_moves = 1;
        }
        else
        {
            mini_moves = 2;
        }
        
        return {mini_moves, maxi_moves};
        
    }
};