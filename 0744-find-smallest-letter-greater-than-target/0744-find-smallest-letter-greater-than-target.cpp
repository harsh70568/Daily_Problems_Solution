class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char c = 'z';
        bool flag = false;
        for(int i = 0; i < letters.size(); i++)
        {
            if(letters[i] > target)
            {
                c = min(c, letters[i]);
                flag = true;
            }
        }
        
        return flag == true ? c : letters[0];
       
        
    }
};