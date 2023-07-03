class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int do_xor = 0;
        for(int i = 0; i < nums.size(); i++) do_xor ^= nums[i];
        return do_xor;
    }
};