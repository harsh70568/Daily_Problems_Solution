class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i+1 < nums.size() && nums[i] == nums[i+1])
            {
                continue;
            }
            else
            {
                cnt++;
                nums[k++] = nums[i];
            }
        }
        return cnt;
    }
};