class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int mini = nums[0];
        set<int> st;
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != mini)
            {
                //count++;
                if(st.find(nums[i]) == st.end())
                {
                    st.insert(nums[i]);
                    count += st.size();
                }
                else
                {
                    count += st.size();
                }
            }
        }
        
        return count;
    }
};