class Solution {
public:
    int numDifferentIntegers(string word) {
        string temp = "";
        set<string> s;
        for(int i = 0; i < word.length(); i++)
        {
            if(word[i] >= 48 && word[i] <= 57)
            {
                if(word[i] == '0'){
                    if(i == word.length()-1) temp += word[i];
                    else if(temp != "")
                    {
                           temp += word[i];
                    }
                    else if(i+1 < word.length() && word[i+1] >= 97 && word[i+1] <= 122)
                    {
                        temp += word[i];
                    }
                   
                }
                
                else
                {
                    temp += word[i];
                }
            }
            else
            {
                if(temp  != "") s.insert(temp);
                temp = "";
            }
        }
        if(temp != "") s.insert(temp);
        
        return s.size();
    }
};