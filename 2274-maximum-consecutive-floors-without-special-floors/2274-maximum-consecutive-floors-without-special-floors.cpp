class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n = special.size();
        
        vector<int> temp;
        temp.push_back(special[0]-bottom);
        temp.push_back(top-special[n-1]);
        
        for(int i = 1; i < n; i++)
        {
            int diff = special[i] - special[i-1];
            temp.push_back(diff-1);
        }
        
        int maxi = *max_element(temp.begin(),temp.end());
        return maxi;
    }
};