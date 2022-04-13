class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i = 0; i < n - 2; i++) {
            int x = nums[i];
            for(int j = i + 1; j < n - 1; j++) {
                int y = nums[j];
                int k = -(x + y);
                if(binary_search(nums.begin() + j + 1, nums.end(), k)) {
                    vector<int> v = {x, y, k};
                    ans.push_back(v);
                    while(i < n - 2 and nums[i + 1] == x)
                        ++i;
                    while(j < n - 1 and nums[j + 1] == y)
                        ++j;
                }
            }
        }
        return ans;
    }
};
