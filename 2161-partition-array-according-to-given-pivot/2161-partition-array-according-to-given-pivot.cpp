class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot)
            {
                ans.push_back(nums[i]);
            }
            else if(pivot == nums[i]) count++;
        }
        
        while(count--)
        {
            ans.push_back(pivot);
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > pivot)
            {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};