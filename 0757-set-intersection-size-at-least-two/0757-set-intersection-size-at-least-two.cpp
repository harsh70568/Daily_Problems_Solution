class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> temp;
        
        // last two values.
        temp.push_back(intervals[0][1] - 1);
        temp.push_back(intervals[0][1]);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] == temp.back())  // one element can skip, as one point get matched
            {
                temp.push_back(intervals[i][1]);
            }
            else if(intervals[i][0] > temp.back())  // two more new points needed
            {
                temp.push_back(intervals[i][1] - 1);
                temp.push_back(intervals[i][1]);
            }
            else if(intervals[i][0] > temp[temp.size()-2])  // 1 point is not in range, one more needed
            {
                temp.push_back(intervals[i][1]);

            }
        }
        
        return temp.size();
    }
};