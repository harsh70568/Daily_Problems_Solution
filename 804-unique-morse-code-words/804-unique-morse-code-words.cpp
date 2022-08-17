class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
         vector<string> temp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
        for(auto it : words)
        {
            string str = it;
            string st = "";
            for(int i = 0; i < str.length(); i++)
            {
                 st += temp[str[i]-'a'];
            }
            s.insert(st);
        }
        return s.size();
    }
};