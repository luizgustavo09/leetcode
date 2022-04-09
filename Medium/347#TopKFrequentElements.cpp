class Solution {
public:
    typedef pair<int, int> ii;
    static inline bool comp(ii a, ii b) {
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mapa;
        for(int v : nums)
            mapa[v]++;
        vector<ii> ans;
        for(auto p: mapa)
            ans.push_back( make_pair(p.second, p.first) );
        sort(ans.begin(), ans.end(), comp);
        vector<int> res(k);
        for(int i = 0; i < k; i++)
            res[i] = ans[i].second;
        return res;
    }
    
};
