class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mpp;
        for(int i =0 ; i< nums.size() ; i++){
            int find = target - nums[i];
            
            if(mpp.find(find)!=mpp.end()){
                return {mpp[find], i};
            } 
            mpp[nums[i]] = i;           
        }
        return {};    
    }
};
