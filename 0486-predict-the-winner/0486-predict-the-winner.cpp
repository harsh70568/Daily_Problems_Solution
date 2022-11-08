class Solution {
public:
    bool solve(int i, int j, vector<int> &nums, int score_a, int score_b, bool flag)
    {
        if(i > j) return score_a >= score_b;
        
        if(flag)   // -> a's turn 
        {
            return solve(i+1, j, nums, score_a+nums[i], score_b, false) | solve(i, j-1, nums, score_a+nums[j], score_b, false);
        }
        else  // -> b's turn
        {
            return solve(i+1, j, nums, score_a, score_b+nums[i], true) && solve(i, j-1, nums, score_a, score_b+nums[j], true);
        }
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n-1, nums, 0, 0, 1);
    }
};