lass Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> m;
        for(int i=0 ; i<n ; i++)
        {
            m[nums[i]]++;
        }
        vector<vector<int>> buckets(n+1);
        for(auto& [num,freq] : m)
        {
            buckets[freq].push_back(num);
        }
        vector<int> result; 
        for(int i=n ; i>=0 && result.size()<k ; i--)
        {
            for(int num : buckets[i])
            {
                result.push_back(num);
                if(result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};
