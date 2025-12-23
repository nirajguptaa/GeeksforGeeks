class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>Ans;
        for(auto it:queries){
            int x=it[0];
            int y=it[1];
            int f=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            int l=upper_bound(arr.begin(),arr.end(),y)-arr.begin();
            Ans.push_back(l-f);
        }
        return Ans;
    }
};