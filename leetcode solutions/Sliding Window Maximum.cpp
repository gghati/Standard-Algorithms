class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        int i=0, j=0;

        list<int> heap;
        while(j<nums.size()) {
            while(heap.size() && heap.back()<nums[j]) heap.pop_back();
            heap.push_back(nums[j]);
            
            if(j<k){
                j++;
                if(j==k) vec.push_back(heap.front());
            }
            else {
                if(nums[i]==heap.front())
                    heap.pop_front();
                i++;
                j++;
                vec.push_back(heap.front());
            } 
        }
        return vec;
    }
};
