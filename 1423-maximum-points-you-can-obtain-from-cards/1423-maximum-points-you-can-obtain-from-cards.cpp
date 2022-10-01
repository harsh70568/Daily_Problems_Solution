class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_pnts = 0;
        for(auto it : cardPoints) total_pnts += it;
        int n = cardPoints.size();
        int maxi = INT_MIN;
        int sum = 0;
        
        int i = 0;
        int j = 0;
        int req_len = n - k;
        if(req_len == 0) return total_pnts;
        while(j < n)
        {
            sum += cardPoints[j];
            if(j-i+1 < req_len)
            {
                j++;
            }
            else
            {
                maxi = max(maxi,total_pnts - sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        
        return maxi;
    }
};