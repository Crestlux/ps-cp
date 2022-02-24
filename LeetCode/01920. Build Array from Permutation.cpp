class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int num_size = nums.size();
        vector<int> ret(num_size);
        for(int i = 0; i < num_size; i++){
            ret[i] = nums[nums[i]];
        }
        return ret;
    }
};
