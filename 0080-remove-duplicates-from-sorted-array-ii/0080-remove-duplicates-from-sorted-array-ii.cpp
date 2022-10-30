class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int i = 0;
        int j = 1;
        vector<int> ans;
        ans.push_back(nums[0]);
        while(j < nums.size())
        {
            if(nums[i] == nums[j] && count == 1)
            {
                ans.push_back(nums[j]);
                count++;
                i = j;
            }
            else if(nums[i] != nums[j])
            {
                ans.push_back(nums[j]);
                count = 1;
                i = j;
            }
            j++;
        }
        nums = ans;
        return ans.size();
    }
};