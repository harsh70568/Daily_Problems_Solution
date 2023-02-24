class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++) mpp[arr[i]]++;
        
        set<pair<int, int>> st;
        for(int i = 0; i < arr.size(); i++)
        {
            if(k == 0)
            {
                if(mpp[arr[i]] > 1)
                {
                    st.insert({arr[i], arr[i]});
                }
            }
            else
            {
                if(mpp[arr[i] + k])
                {
                    st.insert({arr[i], arr[i] + k});
                }
            }
        }
        
        return st.size();
    }
};