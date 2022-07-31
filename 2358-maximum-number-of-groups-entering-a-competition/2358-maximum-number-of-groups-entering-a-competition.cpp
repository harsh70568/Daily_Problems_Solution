class Solution {
public:
    int maximumGroups(vector<int>& grades) {
       // sort(grades.begin(),grades.end());
        if(grades.size() <= 2) return 1;
        int count = 0;
        int i = 0;
        int k = 2;
        while(i < grades.size())
        {
            count++;
            i += k;
            k++;
        }
        return count;
    }
};