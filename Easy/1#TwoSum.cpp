class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        int sz = nums.size();
        sort(v.begin(), v.end());
        int x, y, px, py;
        for(int i = 0; i < sz; i++) {
            x = v[i];
            y = target - x;
            cout << y << endl;
            auto l = v.begin();
            auto r = v.begin() + i;
            if(binary_search(l, r, y)) 
                break;    
            l = v.begin() + i + 1;
            r = v.end();
            if(binary_search(l, r, y)) 
                break;
        }
        px = find(nums.begin(), nums.end(), x) - nums.begin();
        py = find(nums.begin(), nums.begin() + px, y) - nums.begin();
        if(py == px)
            py = find(nums.begin() + px + 1, nums.end(), y) - nums.begin();

        vector<int> ans = {px, py};
        return ans;
    }
};