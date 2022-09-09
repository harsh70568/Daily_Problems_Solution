class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        int n = properties.size();
        int max_def = INT_MIN;
        int count = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(properties[i][1] < max_def) count++;
            max_def = max(max_def,properties[i][1]);
        }
        return count;
    }
};