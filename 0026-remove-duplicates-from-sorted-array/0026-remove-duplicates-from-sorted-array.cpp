class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        
        while(j < nums.size())
        {
            if(nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                ans.push_back(nums[i]);
                i = j;
                j++;
            }
        }
        ans.push_back(nums[i]);
        
        nums = ans;
        
        return nums.size();
    }
};