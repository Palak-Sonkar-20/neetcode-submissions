class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

       
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq) {
            int element = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(element);
        }

        
        vector<int> res;

        for (int i = nums.size(); i >= 0 && res.size() < k; i--) {

            for (int num : bucket[i]) {
                res.push_back(num);

                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};