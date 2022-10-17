class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        for(int i = 0; i < sentence.length(); i++)
        {
            s.insert(sentence[i]);
        }
        
        return s.size() == 26;
    }
};