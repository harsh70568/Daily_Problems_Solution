class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int ori_elem = abs(nums[i]);
            int index = ori_elem - 1;
            
            if(nums[index] < 0)
            {
                ans.push_back(ori_elem);
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};