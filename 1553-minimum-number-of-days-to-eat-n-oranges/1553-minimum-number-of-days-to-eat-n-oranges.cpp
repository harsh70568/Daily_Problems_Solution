class Solution {
public:
    unordered_map<int, int> mpp;
    int solve(int n)
    {
        if(n == 0) return 0;
        
        if(mpp.count(n) != 0) return mpp[n];
        
        int a = INT_MAX;
        int b = INT_MAX;
        int c = INT_MAX;
        
        if(n % 2 == 0)
        {
            a = 1 + solve(n/2);
        }
        if(n % 3 == 0)
        {
            b = 1 + solve(n/3);
        }
        
        if((n % 2 != 0) || (n % 3 != 0)) c = 1 + solve(n-1);
        
        return mpp[n] = min({a,b,c});
    }
    int minDays(int n) {
        return solve(n);
    }
};