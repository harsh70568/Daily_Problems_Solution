class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum < 0)
            {
                mini = min(mini, sum);
            }
        }
        
        return mini == INT_MAX ? 1 : -1*mini+1;                                                  
    }
};