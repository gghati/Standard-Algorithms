class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i < j && numbers[j]+numbers[i]!=target) {
            if(numbers[j]+numbers[i] > target)
                j--;
            else
                i++;
        }
        vector<int> v;
        v.push_back(i+1);
        v.push_back(j+1);
        return v;
    }
};
