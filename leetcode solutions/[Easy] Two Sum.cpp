class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        vector<int> v;
        for (int i:nums){
            int diff = target - i; 
            if(mp.find(diff) == mp.end()){
                mp.insert({i, 0});
            } else {
                v.push_back(find(nums.begin(), nums.end(), diff) - nums.begin());
                v.push_back(mp.size());
                break; 
            }
        }
        return v;
    }
};
