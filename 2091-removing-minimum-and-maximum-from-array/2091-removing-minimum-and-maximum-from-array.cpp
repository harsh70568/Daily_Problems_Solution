class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
            mpp[nums[i]] = i + 1;
        }
        
        int first = mpp[mini];
        int second = mpp[maxi];
        
        int f = max(first,second);
        int s = n - min(first,second) + 1;
        int th = min(mpp[maxi],n - mpp[maxi] + 1) + min(mpp[mini],n - mpp[mini] + 1);
        
        return min(f,min(s,th));
        
        
    }
};