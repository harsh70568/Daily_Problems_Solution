class Solution {
public:
    int bagOfTokensScore(vector<int>& min, int power) {
        sort(min.begin(),min.end());

        
        int max_score = 0;
        int curr_score = 0;
        
        int i = 0;
        int j = min.size()-1;
        if(i < min.size() && min[0] > power) return 0;
        
        while(i <= j)
        {
            if(power >= min[i])
            {
                power -= min[i];
                curr_score++;
                i++;
            }
            else
            {
                power += min[j];
                curr_score--;
                j--;
            }
            max_score = max(max_score,curr_score);
        }
        max_score = max(max_score,curr_score);
        
        return max_score;
    }
};