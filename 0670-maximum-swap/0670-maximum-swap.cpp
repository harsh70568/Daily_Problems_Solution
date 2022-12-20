class Solution {
public:
    void swap(string &str, int i, int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    int maximumSwap(int num) {
        string nums = to_string(num);
        
        unordered_map<char, int> mpp;
        for(int i = 0; i < nums.length(); i++)
        {
            mpp[nums[i]] = i;
        }
        
        string sec = to_string(num);
        sort(sec.begin(), sec.end());
        reverse(sec.begin(), sec.end());
        
        for(int i = 0; i < nums.length(); i++)
        {
            if(nums[i] != sec[i])
            {
                swap(nums, i, mpp[sec[i]]);
                break;
            }
        }
        
        int ans = stoll(nums);
        
        return ans;
    }
};