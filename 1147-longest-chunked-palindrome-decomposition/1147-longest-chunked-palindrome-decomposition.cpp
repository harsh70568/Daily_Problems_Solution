class Solution {
public:
    int longestDecomposition(string text) {
        int i = 0;
        int j = text.length()-1;
        
        string first = "";
        string sec = "";
        int ans = 0;
        while(i < j)
        {
            first += text[i];
            sec += text[j];
            
            reverse(sec.begin(), sec.end());
            
            if(first == sec)
            {
                ans += 2;
                first = "";
                sec = "";
            }
            else
            {
                reverse(sec.begin(), sec.end());
            }
            
            i++;
            j--;
        }
        
        if(first != "" || text.length() % 2 != 0) ans += 1;
        
        return ans;
    }
};