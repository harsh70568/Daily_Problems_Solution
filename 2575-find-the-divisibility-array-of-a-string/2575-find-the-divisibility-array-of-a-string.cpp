class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        
        vector<int> ans(n, 0);
        long long int num = 0;
        for(int i = 0; i < n; i++)
        {
            num *= 10;
            num += word[i] - '0';
            num %= m;
            if(num == 0) ans[i] = 1;
            else ans[i] = 0;
        }
        
        return ans;
    }
};