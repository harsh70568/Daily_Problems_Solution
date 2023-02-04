class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
    
        int i = 0;
        int j = 0;
        int k = s1.length();
        string str = "";
        while(j < s2.length())
        {
            str += s2[j];
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                string temp = str;
                sort(temp.begin(), temp.end());
                if(temp == s1) return true;
                str.erase(str.begin());
                i++;
                j++;  
            }
        }
        
        return false;
    }
};