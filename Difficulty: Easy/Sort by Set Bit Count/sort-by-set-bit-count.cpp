class Solution {
  public:
  static bool compare(int a,int b){
      return __builtin_popcount(a)>__builtin_popcount(b);
  }
    vector<int> sortBySetBitCount(vector<int>& arr) {

        // vector<pair<int,int>>temp;
        // for(int x:arr){
        //     temp.push_back({__builtin_popcount(x),x});
        // }
        // sort(temp.begin(),temp.end(),[](auto &a,auto &b){
        //     return a.first>b.first;
        // });
        // vector<int>ans;
        // for(auto &t:temp){
        //     ans.push_back(t.second);
        // }
        stable_sort(arr.begin(),arr.end(),compare);
        
        return arr;
    }
};