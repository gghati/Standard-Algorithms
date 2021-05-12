class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 4) return vector<vector<int>>();
        
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int k=j+1;
                int l=nums.size()-1;
                while(k<l) {
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        vec.push_back(nums[l]); 
                        ans.insert(vec);
                        k++;
                    }
                    else if(nums[i] + nums[j] + nums[k] + nums[l] < target)                    
                        k++;
                    else l--;
                }
            }
        }
        vector<vector<int>> ret;
        for(vector<int> t: ans) ret.push_back(t);

        return ret;
    }
};
