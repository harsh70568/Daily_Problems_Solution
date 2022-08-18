class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto it : arr)
        {
            mpp[it]++;
        }
        
        vector<int> temp;
        for(auto it : mpp)
        {
            temp.push_back(it.second);
        }
        
        sort(temp.begin(),temp.end(),greater<int>());
        int req_size = arr.size()/2;
        
        int count = 0;
        int sum = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            if(sum >= req_size)
            {
                break;
            }
            sum += temp[i];
            count++;
        }
        return count;
    }
};