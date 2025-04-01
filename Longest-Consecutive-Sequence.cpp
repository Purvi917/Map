class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int longest = 1;
        unordered_set <int> s;
        for(int i=0 ; i<n ; i++)
        {
            s.insert(nums[i]);
        }
        for(auto value : s)
        {
            if(s.find(value-1) == s.end())
            {
                int count = 1;
                int x = value;
                while(s.find(x+1) != s.end())
                {
                    x=x+1;
                    count=count+1;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};
