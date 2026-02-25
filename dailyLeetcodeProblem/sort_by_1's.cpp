class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> num;

        for(int i=0;i<arr.size();i++){
            int count=__builtin_popcount(arr[i]);
            num.push_back({count,arr[i]});
        }

        sort(num.begin(), num.end());

        vector<int> ans;
        for(int i=0;i<num.size();i++){
            ans.push_back(num[i].second);
        }


        return ans;
    }
};