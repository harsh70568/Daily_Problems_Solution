class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        
        string new1;
        string new2;
        new1 += s[0];
        new1 += s[2];
        new2 += s[1];
        new2 += s[3];
        
        
        int sum1 = stoi(new1);
        int sum2 = stoi(new2);
        
        return sum1 + sum2;
    }
};