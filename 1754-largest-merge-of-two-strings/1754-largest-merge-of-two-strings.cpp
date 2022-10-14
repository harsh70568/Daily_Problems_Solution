class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        
        while(word1.length() != 0 && word2.length() != 0)
        {
            if(word1.front() > word2.front())
            {
                ans += word1.front();
                word1.erase(word1.begin());
            }
            else if(word2.front() > word1.front())
            {
                ans += word2.front();
                word2.erase(word2.begin());
            }
            else
            {
                if(word1 >= word2)
                {
                    ans += word1.front();
                    word1.erase(word1.begin());
                }
                else
                {
                    ans += word2.front();
                    word2.erase(word2.begin());
                }
            }
        }
        
        ans += word1;
        ans += word2;
        
        return ans;
    }
};