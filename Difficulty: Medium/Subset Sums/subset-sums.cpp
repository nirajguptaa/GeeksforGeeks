class Solution {
  public:
    void f(int i,int curr,vector<int>& arr,vector<int>& ans){
        int n=arr.size();
        if(i==n){
            ans.push_back(curr);
            return;
        }
        f(i+1,curr+arr[i],arr,ans);
        f(i+1,curr,arr,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        f(0,0,arr,ans);
        return ans;
        
    }
};