class Solution {
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horiCuts, vector<int>& vertiCuts) {
        int max_len = -1;
        int max_bdh = -1;
        
        sort(horiCuts.begin(), horiCuts.end());
        sort(vertiCuts.begin(), vertiCuts.end());
        
        for(int i = 0; i < horiCuts.size()-1; i++)
        {
            max_bdh = max(max_bdh, horiCuts[i+1] - horiCuts[i]);
        }
        
        max_bdh = max({max_bdh, horiCuts[0], h - horiCuts[horiCuts.size()-1]});
        
        for(int i = 0; i < vertiCuts.size()-1; i++)
        {
            max_len = max(max_len, vertiCuts[i+1] - vertiCuts[i]);
        }
        
        max_len = max({max_len, vertiCuts[0], w - vertiCuts[vertiCuts.size()-1]});
        
        return (1LL* max_len * max_bdh % mod) % mod;
    }
};