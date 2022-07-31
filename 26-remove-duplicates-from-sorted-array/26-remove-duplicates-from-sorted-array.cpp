class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        vector<int> ans;
        ans.push_back(nums[0]);
        while(j < nums.size())
        {
            if(nums[j] != nums[i])
            {
                ans.push_back(nums[j]);
                i = j;
            }
            j++;
        }
        nums = ans;
        return ans.size();
    }
};