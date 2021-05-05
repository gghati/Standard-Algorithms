class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            vec.push_back({nums[n-i-1]});
            vector<int> cvec;
            cvec.assign(nums.begin(), nums.end()-i-1);
            auto res = subsets(cvec);
            for(auto t: res) {
                if(t.size() && t.back()<nums[n-1-i]) { 
                    t.push_back(nums[n-1-i]);
                    vec.push_back(t); 
                }
            }            
        }
        vec.push_back({});
        return vec;
    }
};
