class Solution {
public:
    int partitionString(string s) {
        int count = 1;    // count varibale to store the answer
        unordered_map<char,int> mpp;
        for(int i = 0; i < s.length(); i++)
        {
            // if we found the element that is already there in the substring we increase our count as we got a partition
            if(mpp.find(s[i]) != mpp.end())   
            {
                count++;
                mpp.clear();  // reset our map
            }
            mpp[s[i]]++;   // adding all charcters to our map
        }
        
        return count;
    }
};