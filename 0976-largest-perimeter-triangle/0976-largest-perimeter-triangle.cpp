class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max_peri = 0;
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] + nums[i+1] > nums[i+2])
            {
                int sum = nums[i] + nums[i+1] + nums[i+2];
                max_peri = max(max_peri, sum);
            }
        }
        
        return max_peri;
    }
};