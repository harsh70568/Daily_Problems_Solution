class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) return 32;
        if(n == 1) return 0;

        if(n % 2 == 0)
        {
            return 1 + integerReplacement(n/2);
        }
        else
        {
            int odd1 = 1 + integerReplacement(n-1);
            int odd2 = 1 + integerReplacement(n+1);
            return min(odd1,odd2);
        }
        
    }
};