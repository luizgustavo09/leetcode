class Solution {
public:
    typedef long long int ll;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i = 0; i < n - 3; i++) {
            ll x = nums[i];
            for(int j = i + 1; j < n - 2; j++) {
                ll y = nums[j];
                for(int k = j + 1; k < n - 1; k++) {
                    ll z = nums[k];
                    ll value = target - x - y - z;
                    if(binary_search(nums.begin() + k + 1, nums.end(), value)) {
                        vector<int> v = {(int)x, (int)y, (int)z, (int)value};
                        ans.push_back(v);
                        while(i < n - 3 and nums[i + 1] == x)
                            ++i;
                        while(j < n - 2 and nums[j + 1] == y)
                            ++j;
                        while(k < n - 1 and nums[k + 1] == z)
                            ++k;
                    }
                }
            }
        }
        return ans;
    }
};
