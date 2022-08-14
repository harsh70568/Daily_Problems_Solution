class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.size();
        vector<vector<string>> ans(n);
        sort(products.begin(),products.end());
        string c = "";
        for(int i = 0; i < searchWord.size(); i++)
        {
            vector<string> temp;
            c += searchWord[i];
            for(int j = 0; j < products.size(); j++)
            {
                if(temp.size() == 3) break;
                if(c == products[j].substr(0,i+1))
                {
                    temp.push_back(products[j]);
                }
            }
            ans[i] = temp;
        }
        return ans;
        
    }
};