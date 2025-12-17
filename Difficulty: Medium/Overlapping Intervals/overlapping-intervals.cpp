class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int first=arr[0][0];
        int last=arr[0][1];
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i][0]<=last){
                last=max(last,arr[i][1]);
            }else{
                ans.push_back({first,last});
                first=arr[i][0];
                last=arr[i][1];
            }
            
        }
        ans.push_back({first,last});
        return ans;
    }
};