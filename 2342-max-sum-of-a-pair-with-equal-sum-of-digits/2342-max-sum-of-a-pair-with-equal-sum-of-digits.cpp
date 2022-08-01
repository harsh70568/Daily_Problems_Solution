class Solution {
public:
    int sum_of_digits(int n)
    {
        int s = 0;
        while(n)
        {
            s += (n%10);
            n /= 10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = sum_of_digits(nums[i]);
            mpp[sum].push_back(nums[i]);
        }
        for(auto it : mpp)
        {
            vector<int> temp = it.second;
            sort(temp.begin(),temp.end(),greater<int>());
            if(temp.size() > 1){
              int s = temp[0]+temp[1];
            maxi = max(maxi,s);
            
            }
        }
        return (maxi == INT_MIN) ? -1 : maxi;
    }
};