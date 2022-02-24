class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int vecsize = static_cast<int>(nums.size()), sum = 0, i, j;
        unordered_map<int,int> m;
        vector<int>ret(2);
        for(i = 0; i < vecsize; i++){
            int val = target - nums[i];
            if(m.find(val)!=m.end()){
                ret[0] = m[val];
                ret[1] = i;
                break;
            }
            else m[nums[i]] = i;
        }
        return ret;
    }
};
