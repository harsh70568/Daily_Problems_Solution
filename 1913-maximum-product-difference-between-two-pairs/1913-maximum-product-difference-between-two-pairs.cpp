class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int second = nums[0]*nums[1];
        int first = nums[n-1]*nums[n-2];
        
        return first - second;
    }
};