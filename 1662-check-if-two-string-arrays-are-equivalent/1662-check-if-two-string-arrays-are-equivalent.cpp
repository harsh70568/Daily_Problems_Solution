class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        vector<string> ans(2);
        for(int i = 0; i < word1.size(); i++)
        {
            ans[0] += word1[i];
        }
        
        for(int i = 0; i < word2.size(); i++)
        {
            ans[1] += word2[i];
        }
        
        return  ans[0] == ans[1];
    }
};