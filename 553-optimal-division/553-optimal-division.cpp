class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        
        string ans = "";
        if(n == 0) return  "";
        if(n == 1) return to_string(nums[0]);
        if(n == 2)
        {
            ans += to_string(nums[0]);
            ans += '/';
            ans += to_string(nums[1]);
            return ans;
        }
        ans += to_string(nums[0]);
        ans += '/';
        ans += '(';
        for(int i = 1; i < n; i++)
        {
            ans += to_string(nums[i]);
            if(i != n-1) ans += '/';
        }
        ans += ')';
        return ans;
    }
};