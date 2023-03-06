class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> st(arr.begin(), arr.end());
        
        int cnt = 0;
        for(int i = 0; i < 5000; i++)
        {
            if(st.find(i+1) == st.end())
            {
                cnt++;
                if(cnt == k) return i+1;
            }
        }
        
        return -1;
    }
};