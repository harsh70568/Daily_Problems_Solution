class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = -1;
        int elem2 = -1;
        int count1 = 0;
        int count2 = 0;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(elem1 == nums[i]) count1++;
            else if(elem2 == nums[i]) count2++;
            else if(count1 == 0)
            {
                elem1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                elem2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == elem1) count1++;
            if(nums[i] == elem2) count2++;
        }
        
        if(count1 > n/3) ans.push_back(elem1);
        if(count2 > n/3 && elem2 != elem1) ans.push_back(elem2);
        return ans;
    }
};