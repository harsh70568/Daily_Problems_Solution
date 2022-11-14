class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        unordered_map<char, int> mpp;
        
        
        string s = "";
        for(int i = 0; i < guess.size(); i++)
        {
            if(guess[i] == secret[i])
            {
                bulls++;
            }
            else
            {
                mpp[secret[i]]++;
            }
        }
        
        for(int i = 0; i < guess.size(); i++)
        {
            if(guess[i] != secret[i] && mpp[guess[i]] > 0)
            {
                cows++;
                mpp[guess[i]]--;
            }
        }
        
        s += to_string(bulls) + 'A' + to_string(cows) + 'B';
        
        return s;
    }
};