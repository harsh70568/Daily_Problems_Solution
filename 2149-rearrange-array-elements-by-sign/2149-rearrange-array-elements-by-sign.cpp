class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n/2 || j < n/2)
        {
            ans[k++] = pos[i];
            ans[k++] = neg[j];
            i++;
            j++;
        }
        
        
        return ans;
    }
};