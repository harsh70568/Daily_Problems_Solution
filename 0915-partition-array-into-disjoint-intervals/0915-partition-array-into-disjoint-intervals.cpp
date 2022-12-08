class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxi = nums[0];
        int raaste_ki_maxi = nums[0];
        
        int ans = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < maxi)
            {
                ans = i+1;
                maxi = raaste_ki_maxi;
            }
            else if(nums[i] > raaste_ki_maxi)
            {
                raaste_ki_maxi = nums[i];
            }
        }
        
        return ans;
    }
};