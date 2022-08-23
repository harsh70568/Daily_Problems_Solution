class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) return 32;
        if(n == 1) return 0;
        int mini = INT_MAX;
        if(n % 2 == 0)
        {
            mini =  1 + integerReplacement(n/2);
        }
        else
        {
            mini = min(mini, 1 + integerReplacement(n-1));
            mini = min(mini,1 + integerReplacement(n+1));
            
        }
        return mini;
    }
};