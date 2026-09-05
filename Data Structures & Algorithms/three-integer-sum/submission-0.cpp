class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int l =0;
        for(l ; l<nums.size() ;l++){
            int r=nums.size()-1;
            int m = l+1;
            if(l>0 && nums[l]==nums[l-1]) continue;
                while(m<r){
                    int sum = nums[l]+nums[m]+nums[r];
                    if(sum==0){
                        res.push_back({nums[l], nums[m],nums[r]});
                    
                        while (m < r && nums[m] == nums[m + 1]){
                                m++;}

                        while (m < r && nums[r] == nums[r - 1]){
                                r--;} 
                        m++;
                        r--;
                    }
                    if(sum<0) m++;
                    if(sum>0) r--;
                }
        } 
        return res;
    }
};
