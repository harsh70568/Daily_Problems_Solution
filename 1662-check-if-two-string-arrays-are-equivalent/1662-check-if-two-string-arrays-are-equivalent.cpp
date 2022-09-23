class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1 = "";
        string ans2 = "";
        
        for(int i = 0; i < word1.size(); i++)
        {
            for(int j = 0; j < word1[i].length(); j++)
            {
                ans1 += word1[i][j];
            }
        }
        
        for(int i = 0; i < word2.size(); i++)
        {
            for(int j = 0; j < word2[i].length(); j++)
            {
                ans2 += word2[i][j];
            }
        }
        
        return  ans1 == ans2;
    }
};