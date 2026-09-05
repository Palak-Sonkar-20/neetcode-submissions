class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1) , right(n, 1);
        vector<int> output(n);
        
        int l = 1;
        for(int i = 1 ; i<n ; i++){
            l*=nums[i-1];
            left[i]=l; 
        }
        int r = 1;
        for(int i = n-2 ; i>=0; i--){
            r*=nums[i+1];
            right[i]=r;

        }
        for(int i = 0 ; i<n ; i++){
            output[i] = left[i]*right[i];
            
        }
    return output;
    }
};
